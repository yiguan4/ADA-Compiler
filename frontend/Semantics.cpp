#include <vector>
#include <set>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/util/CrossReferencer.h"
#include "SemanticErrorHandler.h"
#include "Semantics.h"

namespace intermediate { namespace symtab {
    int Symtab::unnamedIndex = 0;
}}

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;
using namespace intermediate::util;

Object Semantics::visitProgram(ADAParser::ProgramContext *ctx)
{
    visit(ctx->programHeader());
    visit(ctx->block()->declarations());
    visit(ctx->block()->compoundStatement());

    // Print the cross-reference table.
    CrossReferencer crossReferencer;
    crossReferencer.print(symtabStack);

    return nullptr;
}

Object Semantics::visitProgramHeader(ADAParser::ProgramHeaderContext *ctx)
{
    ADAParser::ProgramIdentifierContext *idCtx = ctx->programIdentifier();
    string programName = idCtx->IDENTIFIER()->getText();  // don't shift case

    programId = symtabStack->enterLocal(programName, PROGRAM);
    programId->setRoutineSymtab(symtabStack->push());

    symtabStack->setProgramId(programId);
    symtabStack->getLocalSymtab()->setOwner(programId);

    idCtx->entry = programId;
    return nullptr;
}

Object Semantics::visitConstantDefinition(
                                ADAParser::ConstantDefinitionContext *ctx)
{
    ADAParser::ConstantIdentifierContext *idCtx = ctx->constantIdentifier();
    string constantName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

    if (constantId == nullptr)
    {
        ADAParser::ConstantContext *constCtx = ctx->constant();
        Object constValue = visit(constCtx);

        constantId = symtabStack->enterLocal(constantName, CONSTANT);
        constantId->setValue(constValue);
        constantId->setType(constCtx->type);

        idCtx->entry = constantId;
        idCtx->type  = constCtx->type;
    }
    else
    {
        error.flag(REDECLARED_IDENTIFIER, ctx);

        idCtx->entry = constantId;
        idCtx->type  = Predefined::integerType;
    }

    constantId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitConstant(ADAParser::ConstantContext *ctx)
{
    if (ctx->IDENTIFIER() != nullptr)
    {
        string constantName = toLowerCase(ctx->IDENTIFIER()->getText());
        SymtabEntry *constantId = symtabStack->lookup(constantName);

        if (constantId != nullptr)
        {
            Kind kind = constantId->getKind();
            if ((kind != CONSTANT) && (kind != ENUMERATION_CONSTANT))
            {
                error.flag(INVALID_CONSTANT, ctx);
            }

            ctx->type  = constantId->getType();
            ctx->value = constantId->getValue();

            constantId->appendLineNumber(ctx->getStart()->getLine());
        }
        else
        {
            error.flag(UNDECLARED_IDENTIFIER, ctx);
            ctx->type = Predefined::integerType;
            ctx->value = 0;
        }
    }
    else if (ctx->characterConstant() != nullptr)
    {
        ctx->type = Predefined::charType;
        ctx->value = ctx->getText()[1];
    }
    else if (ctx->stringConstant() != nullptr)
    {
        string ADAString = ctx->stringConstant()->STRING()->getText();
        string unquoted = ADAString.substr(1, ADAString.length()-2);

        size_t pos = 0;
        while ((pos = unquoted.find("''", pos)) != string::npos)
        {
            unquoted.replace(pos++, 2, "'");
        }

        pos = 0;
        while ((pos = unquoted.find("\"", pos)) != string::npos)
        {
            unquoted.replace(pos++, 2, "\\\"");
        }

        ctx->type = Predefined::stringType;
        ctx->value = new string(unquoted);
    }
    else  // number
    {
        ADAParser::UnsignedNumberContext *unsignedCtx = ctx->unsignedNumber();

        if (unsignedCtx->integerConstant() != nullptr)
        {
            ctx->type = Predefined::integerType;
            ctx->value = stoi(ctx->getText());
        }
        else
        {
            ctx->type = Predefined::realType;
            ctx->value = stod(ctx->getText());
        }
    }

    return ctx->value;
}

Object Semantics::visitTypeDefinition(ADAParser::TypeDefinitionContext *ctx)
{
    ADAParser::TypeIdentifierContext *idCtx = ctx->typeIdentifier();
    string typeName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *typeId = symtabStack->lookupLocal(typeName);

    ADAParser::TypeSpecificationContext *typespecCtx =
                                                    ctx->typeSpecification();

    // If it's a record type, create a named record type.
    ADAParser::RecordTypespecContext *recordTypespecCtx =
                dynamic_cast<ADAParser::RecordTypespecContext *>(typespecCtx);
    if (recordTypespecCtx != nullptr)
    {
        typeId = createRecordType(recordTypespecCtx, typeName);
    }

    // Enter the type name of any other type into the symbol table.
    else if (typeId == nullptr)
    {
        ADAParser::TypeSpecificationContext *typeCtx =
                                                    ctx->typeSpecification();
        visit(typeCtx);

        typeId = symtabStack->enterLocal(typeName, TYPE);
        typeId->setType(typeCtx->type);
        typeCtx->type->setIdentifier(typeId);
    }
    else
    {
        error.flag(REDECLARED_IDENTIFIER, ctx);
    }

    idCtx->entry = typeId;
    idCtx->type  = typespecCtx->type;

    typeId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitRecordTypespec(ADAParser::RecordTypespecContext *ctx)
{
    // Create an unnamed record type.
    string recordTypeName = Symtab::generateUnnamedName();
    createRecordType(ctx, recordTypeName);

    return nullptr;
}

SymtabEntry *Semantics::createRecordType(
                    ADAParser::RecordTypespecContext *recordTypeSpecCtx,
                    string recordTypeName)
{
    ADAParser::RecordTypeContext *recordTypeCtx =
                                            recordTypeSpecCtx->recordType();
    Typespec *recordType = new Typespec(RECORD);

    SymtabEntry *recordTypeId = symtabStack->enterLocal(recordTypeName, TYPE);
    recordTypeId->setType(recordType);
    recordType->setIdentifier(recordTypeId);

    string recordTypePath = createRecordTypePath(recordType);
    recordType->setRecordTypePath(recordTypePath);

    // Enter the record fields into the record type's symbol table.
    Symtab *recordSymtab = createRecordSymtab(recordTypeCtx->recordFields(),
                                             recordTypeId);
    recordType->setRecordSymtab(recordSymtab);

    recordTypeCtx->entry    = recordTypeId;
    recordTypeSpecCtx->type = recordType;

    return recordTypeId;
}

string Semantics::createRecordTypePath(Typespec *recordType)
{
    SymtabEntry *recordId = recordType->getIdentifier();
    SymtabEntry *parentId = recordId->getSymtab()->getOwner();
    string path = recordId->getName();

    while (   (parentId->getKind() == TYPE)
           && (parentId->getType()->getForm() == RECORD))
    {
        path = parentId->getName() + "$" + path;
        parentId = parentId->getSymtab()->getOwner();
    }

    path = parentId->getName() + "$" + path;
    return path;
}

Symtab *Semantics::createRecordSymtab(
                ADAParser::RecordFieldsContext *ctx, SymtabEntry *ownerId)
{
    Symtab *recordSymtab = symtabStack->push();

    recordSymtab->setOwner(ownerId);
    visit(ctx->variableDeclarationsList());
    recordSymtab->resetVariables(RECORD_FIELD);
    symtabStack->pop();

    return recordSymtab;
}

Object Semantics::visitSimpleTypespec(ADAParser::SimpleTypespecContext *ctx)
{
    visit(ctx->simpleType());
    ctx->type = ctx->simpleType()->type;

    return nullptr;
}

Object Semantics::visitTypeIdentifierTypespec(
                            ADAParser::TypeIdentifierTypespecContext *ctx)
{
    visit(ctx->typeIdentifier());
    ctx->type = ctx->typeIdentifier()->type;

    return nullptr;
}

Object Semantics::visitTypeIdentifier(ADAParser::TypeIdentifierContext *ctx)
{
    string typeName = toLowerCase(ctx->IDENTIFIER()->getText());
    SymtabEntry *typeId = symtabStack->lookup(typeName);

    if (typeId != nullptr)
    {
        if (typeId->getKind() != TYPE)
        {
            error.flag(INVALID_TYPE, ctx);
            ctx->type = Predefined::integerType;
        }
        else
        {
            ctx->type = typeId->getType();
        }

        typeId->appendLineNumber(ctx->start->getLine());
    }
    else
    {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    ctx->entry = typeId;
    return nullptr;
}

Object Semantics::visitEnumerationTypespec(
                                ADAParser::EnumerationTypespecContext *ctx)
{
    Typespec *enumType = new Typespec(ENUMERATION);
    vector<SymtabEntry *> *constants = new vector<SymtabEntry *>();
    int value = -1;

    // Loop over the enumeration constants.
    for (ADAParser::EnumerationConstantContext *constCtx :
                                ctx->enumerationType()->enumerationConstant())
    {
        ADAParser::ConstantIdentifierContext *constIdCtx =
                                                constCtx->constantIdentifier();
        string constantName = toLowerCase(constIdCtx->IDENTIFIER()->getText());
        SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

        if (constantId == nullptr)
        {
            constantId = symtabStack->enterLocal(constantName,
                                                 ENUMERATION_CONSTANT);
            constantId->setType(enumType);
            constantId->setValue(++value);

            constants->push_back(constantId);
        }
        else
        {
            error.flag(REDECLARED_IDENTIFIER, constCtx);
        }

        constIdCtx->entry = constantId;
        constIdCtx->type  = enumType;

        constantId->appendLineNumber(ctx->getStart()->getLine());
    }

    enumType->setEnumerationConstants(constants);
    ctx->type = enumType;

    return nullptr;
}

Object Semantics::visitSubrangeTypespec(
                                    ADAParser::SubrangeTypespecContext *ctx)
{
    Typespec *type = new Typespec(SUBRANGE);
    ADAParser::SubrangeTypeContext *subCtx = ctx->subrangeType();
    ADAParser::ConstantContext *minCtx = subCtx->constant()[0];
    ADAParser::ConstantContext *maxCtx = subCtx->constant()[1];

    Object minObj = visit(minCtx);
    Object maxObj = visit(maxCtx);

    Typespec *minType = minCtx->type;
    Typespec *maxType = maxCtx->type;

    if (   (   (minType->getForm() != SCALAR)
    		&& (minType->getForm() != ENUMERATION))
        || (minType == Predefined::realType)
        || (minType == Predefined::stringType))
    {
        error.flag(INVALID_CONSTANT, minCtx);
        minType = Predefined::integerType;
        minObj  = 0;
    }

    int minValue;
    int maxValue;

    if (minType == Predefined::integerType)
    {
    	minValue = minObj.as<int>();
    	maxValue = maxObj.as<int>();
    }
    else if (minType == Predefined::charType)
    {
    	minValue = minObj.as<char>();
    	maxValue = maxObj.as<char>();
    }
    else  // enumeration constants
    {
    	minValue = minCtx->value.as<int>();
    	maxValue = maxCtx->value.as<int>();
    }

    if ((maxType != minType) || (minValue > maxValue))
    {
        error.flag(INVALID_CONSTANT, maxCtx);
        maxType = minType;
        maxObj  = minObj;
    }

    type->setSubrangeBaseType(minType);
    type->setSubrangeMinValue(minValue);
    type->setSubrangeMaxValue(maxValue);

    ctx->type = type;
    return nullptr;
}

Object Semantics::visitArrayTypespec(ADAParser::ArrayTypespecContext *ctx)
{
    Typespec *arrayType = new Typespec(ARRAY);
    ADAParser::ArrayTypeContext *arrayCtx = ctx->arrayType();
    ADAParser::ArrayDimensionListContext *listCtx =
                                                arrayCtx->arrayDimensionList();

    ctx->type = arrayType;

    // Loop over the array dimensions.
    int count = listCtx->simpleType().size();
    for (int i = 0; i < count; i++)
    {
        ADAParser::SimpleTypeContext *simpleCtx = listCtx->simpleType()[i];
        visit(simpleCtx);
        arrayType->setArrayIndexType(simpleCtx->type);
        arrayType->setArrayElementCount(typeCount(simpleCtx->type));

        if (i < count-1)
        {
            Typespec *elmtType = new Typespec(ARRAY);
            arrayType->setArrayElementType(elmtType);
            arrayType = elmtType;
        }
    }

    visit(arrayCtx->typeSpecification());
    Typespec *elmtType = arrayCtx->typeSpecification()->type;
    arrayType->setArrayElementType(elmtType);

    return nullptr;
}

int Semantics::typeCount(Typespec *type)
{
    int count = 0;

    if (type->getForm() == ENUMERATION)
    {
        vector<SymtabEntry *> *constants = type->getEnumerationConstants();
        count = constants->size();
    }
    else  // subrange
    {
        int minValue = type->getSubrangeMinValue();
        int maxValue = type->getSubrangeMaxValue();
        count = maxValue - minValue + 1;
    }

    return count;
}

Object Semantics::visitVariableDeclarations(
                                ADAParser::VariableDeclarationsContext *ctx)
{
    ADAParser::TypeSpecificationContext *typeCtx = ctx->typeSpecification();
    visit(typeCtx);

    ADAParser::VariableIdentifierListContext *listCtx =
                                                ctx->variableIdentifierList();

    // Loop over the variables being declared.
    for (ADAParser::VariableIdentifierContext *idCtx :
                                                listCtx->variableIdentifier())
    {
        int lineNumber = idCtx->getStart()->getLine();
        string variableName = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

        if (variableId == nullptr)
        {
            variableId = symtabStack->enterLocal(variableName, VARIABLE);
            variableId->setType(typeCtx->type);

            // Assign slot numbers to local variables.
            Symtab *symtab = variableId->getSymtab();
            if (symtab->getNestingLevel() > 1)
            {
                variableId->setSlotNumber(symtab->nextSlotNumber());
            }

            idCtx->entry = variableId;
        }
        else
        {
            error.flag(REDECLARED_IDENTIFIER, ctx);
        }

        variableId->appendLineNumber(lineNumber);
    }

    return nullptr;
}


Object Semantics::visitSubprogramBody(
                                    ADAParser::SubprogramBodyContext *ctx)
{
    ADAParser::FunctionHeadContext  *funcCtx = ctx->functionHead();
    ADAParser::ProcedureHeadContext *procCtx = ctx->procedureHead();
    ADAParser::RoutineIdentifierContext *idCtx = nullptr;
    ADAParser::ParametersContext *parameters = nullptr;
    bool functionDefinition = funcCtx != nullptr;
    Typespec *returnType = nullptr;
    string routineName;

    if (functionDefinition)
    {
        idCtx = funcCtx->routineIdentifier();
        parameters = funcCtx->parameters();
    }
    else
    {
        idCtx = procCtx->routineIdentifier();
        parameters = procCtx->parameters();
    }

    routineName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

    if (routineId != nullptr)
    {
        error.flag(REDECLARED_IDENTIFIER,
                   ctx->getStart()->getLine(), routineName);
        return nullptr;
    }

    if(parameters != nullptr){
        int paraSize = parameters->parameterDeclarationsList()->parameterDeclarations().size();

        for(int i = 0; i < paraSize; i++){
        	ADAParser::ParameterDeclarationsContext *decCtx = parameters->parameterDeclarationsList()->parameterDeclarations(i);
        	if(decCtx->OUT()== nullptr){
        		int statSize = ctx->block()->compoundStatement()->statementList()->statement().size();
        		for(int j = 0; j < statSize; j++){
        			ADAParser::StatementContext *statCtx = ctx->block()->compoundStatement()->statementList()->statement(j);
        			int idfSize = decCtx->parameterIdentifierList()->parameterIdentifier().size();
        			for(int k = 0; k < idfSize; k++){
        				if(statCtx->assignmentStatement() != nullptr){
							if(statCtx->assignmentStatement()->lhs()->variable()->getText()
								== decCtx->parameterIdentifierList()->parameterIdentifier(k)->IDENTIFIER()->getText()){
								error.flag(INVALID_PARAMETER,ctx->getStart()->getLine(), routineName);
								return nullptr;
							}
        				}
        			}

        		}
        	}
        }

    }

    if(functionDefinition){
    	bool hasReturn = false;
    	int statSize = ctx->block()->compoundStatement()->statementList()->statement().size();
		for(int i = 0; i < statSize; i++){
			ADAParser::StatementContext *statCtx = ctx->block()->compoundStatement()->statementList()->statement(i);
			if(statCtx->returnStatement() != nullptr){
				hasReturn = true;
			}
		}
		if(!hasReturn){
			error.flag(EXPECTED_RETURN, ctx->getStart()->getLine(), routineName);
			return nullptr;
		}
    }

    routineId = symtabStack->enterLocal(
                    routineName, functionDefinition ? FUNCTION : PROCEDURE);
    routineId->setRoutineCode(DECLARED);
    idCtx->entry = routineId;

    // Append to the parent routine's list of subroutines.
    SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
    parentId->appendSubroutine(routineId);

    routineId->setRoutineSymtab(symtabStack->push());
    idCtx->entry = routineId;

    Symtab *symtab = symtabStack->getLocalSymtab();
    symtab->setOwner(routineId);

    if (parameters != nullptr)
    {
        vector<SymtabEntry *> *parameterIds =
                                visit(parameters->parameterDeclarationsList())
                                                .as<vector<SymtabEntry *>*>();
        routineId->setRoutineParameters(parameterIds);

        for (SymtabEntry *parmId : *parameterIds)
        {
            parmId->setSlotNumber(symtab->nextSlotNumber());
        }
    }

    if (functionDefinition)
    {
        ADAParser::TypeIdentifierContext *typeIdCtx =
                                                funcCtx->typeIdentifier();
        visit(typeIdCtx);
        returnType = typeIdCtx->type;

        if (returnType->getForm() != SCALAR)
        {
            error.flag(INVALID_RETURN_TYPE, typeIdCtx);
            returnType = Predefined::integerType;
        }

        routineId->setType(returnType);
        idCtx->type = returnType;
    }
    else
    {
        idCtx->type = nullptr;
    }

    visit(ctx->block()->declarations());

    // Enter the function's associated variable into its symbol table.
    if (functionDefinition)
    {
        SymtabEntry *assocVarId =
                            symtabStack->enterLocal(routineName, VARIABLE);
        assocVarId->setSlotNumber(symtab->nextSlotNumber());
        assocVarId->setType(returnType);
    }

    visit(ctx->block()->compoundStatement());
    routineId->setExecutable(ctx->block()->compoundStatement());

    symtabStack->pop();
    return nullptr;
}

Object Semantics::visitParameterDeclarationsList(
                            ADAParser::ParameterDeclarationsListContext *ctx)
{
    vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

    // Loop over the parameter declarations.
    for (ADAParser::ParameterDeclarationsContext *dclCtx :
                                                ctx->parameterDeclarations())
    {
        vector<SymtabEntry *> parameterSublist =
                                    visit(dclCtx).as<vector<SymtabEntry *>>();
        for (SymtabEntry *id : parameterSublist) parameterList->push_back(id);
    }

    return parameterList;
}

Object Semantics::visitParameterDeclarations(
                                ADAParser::ParameterDeclarationsContext *ctx)
{
    Kind kind = ctx->OUT() != nullptr ? REFERENCE_PARAMETER : VALUE_PARAMETER;
    ADAParser::TypeIdentifierContext *typeCtx = ctx->typeIdentifier();

    visit(typeCtx);
    Typespec *parmType = typeCtx->type;

    vector<SymtabEntry *> parameterSublist;

    // Loop over the parameter identifiers.
    ADAParser::ParameterIdentifierListContext *listCtx =
                                                ctx->parameterIdentifierList();
    for (ADAParser::ParameterIdentifierContext *idCtx :
                                                listCtx->parameterIdentifier())
    {
        int lineNumber = idCtx->getStart()->getLine();
        string parmName = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

        if (parmId == nullptr)
        {
            parmId = symtabStack->enterLocal(parmName, kind);
            parmId->setType(parmType);
        }
        else
        {
            error.flag(REDECLARED_IDENTIFIER, idCtx);
        }

        idCtx->entry = parmId;
        idCtx->type  = parmType;

        parameterSublist.push_back(parmId);
        parmId->appendLineNumber(lineNumber);
    }

    return parameterSublist;
}

Object Semantics::visitAssignmentStatement(
                                ADAParser::AssignmentStatementContext *ctx)
{
    ADAParser::LhsContext *lhsCtx = ctx->lhs();
    ADAParser::RhsContext *rhsCtx = ctx->rhs();

    visitChildren(ctx);

    Typespec *lhsType = lhsCtx->type;
    Typespec *rhsType = rhsCtx->expression()->type;

    if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType))
    {
        error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
    }

    return nullptr;
}

Object Semantics::visitLhs(ADAParser::LhsContext *ctx)
{
    ADAParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitIfStatement(ADAParser::IfStatementContext *ctx)
{
	ADAParser::ExpressionContext     *exprCtx  = ctx->ifCondition()->expression();
    ADAParser::TrueStatementListContext  *trueCtx  = ctx->trueStatementList();
    ADAParser::FalseStatementListContext *falseCtx = ctx->falseStatementList();

    visit(exprCtx);
    Typespec *expr_type = exprCtx->type;

    if (!TypeChecker::isBoolean(expr_type))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }


    if(ctx->ELSIF(0)!=nullptr){
    	for(int i=0; i< ctx->ELSIF().size(); i++){
    		ADAParser::ExpressionContext   *elsifExpr  = ctx->elsifCondition(i)->expression();
    		visit(elsifExpr);
    		if (!TypeChecker::isBoolean(elsifExpr->type))
    	    {
    	        error.flag(TYPE_MUST_BE_BOOLEAN, elsifExpr);
    	    }
    	}
    }

    visit(trueCtx);
    for(int i=0; i<ctx->ELSIF().size();i++){
		visit(ctx->elseStatementList(i));
	}

    if (falseCtx != nullptr) visit(falseCtx);

    return nullptr;
}

Object Semantics::visitCaseStatement(ADAParser::CaseStatementContext *ctx)
{
    ADAParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    Form exprTypeForm = exprType->getForm();

    if (   (   (exprTypeForm != SCALAR)
            && (exprTypeForm != ENUMERATION)
            && (exprTypeForm != SUBRANGE))
        || (exprType == Predefined::realType)
        || (exprType == Predefined::stringType))
    {
        error.flag(TYPE_MISMATCH, exprCtx);
        exprType = Predefined::integerType;
    }

    set<int> constants;
    ADAParser::CaseBranchListContext *branchListCtx = ctx->caseBranchList();

    // Loop over the CASE branches.
    for (ADAParser::CaseBranchContext *branchCtx :
                                                branchListCtx->caseBranch())
    {
        ADAParser::CaseConstantListContext *constListCtx =
                                                branchCtx->caseConstantList();
        ADAParser::StatementContext *stmtCtx = branchCtx->statement();

        if (constListCtx != nullptr)
        {
            // Loop over the CASE constants in each branch.
            for (ADAParser::CaseConstantContext *caseConstCtx :
                                                constListCtx->caseConstant())
            {
                ADAParser::ConstantContext *constCtx =
                                                    caseConstCtx->constant();
                Object constValue = visit(constCtx);

                caseConstCtx->type  = constCtx->type;
                caseConstCtx->value = 0;

                if (constCtx->type != exprType)
                {
                    error.flag(TYPE_MISMATCH, constCtx);
                }
                else if (   (constCtx->type == Predefined::integerType)
                         || (constCtx->type->getForm() == ENUMERATION))
                {
                    caseConstCtx->value = constValue.as<int>();
                }
                else if (constCtx->type == Predefined::charType)
                {
                    caseConstCtx->value = constValue.as<char>();
                }

                if (constants.find(caseConstCtx->value) != constants.end())
                {
                    error.flag(DUPLICATE_CASE_CONSTANT, constCtx);
                }
                else
                {
                    constants.insert(caseConstCtx->value);
                }
            }
        }

        if (stmtCtx != nullptr) visit(stmtCtx);
    }

    return nullptr;
}

Object Semantics::visitLoopStatement(ADAParser::LoopStatementContext *ctx) {
	if(ctx->whileStatement() != nullptr){
		ADAParser::ExpressionContext *exprCtx = ctx->whileStatement()->expression();
		visit(exprCtx);
		Typespec *exprType = exprCtx->type;

		if (!TypeChecker::isBoolean(exprType)){
			error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
		}

	}
	else if(ctx->forStatement() != nullptr){
		ADAParser::VariableContext *varCtx = ctx->forStatement()->variable();
		visit(varCtx);

		string controlName = toLowerCase(varCtx->variableIdentifier()->getText());
		Typespec *controlType = Predefined::integerType;

		if (varCtx->entry != nullptr)
		{
			controlType = varCtx->type;
			if (   (controlType->getForm() != SCALAR )
				|| (controlType == Predefined::realType)
				|| (controlType == Predefined::stringType))
			{
				error.flag(INVALID_CONTROL_VARIABLE, varCtx);
			}
		}
		else
		{
			error.flag(UNDECLARED_IDENTIFIER, ctx->getStart()->getLine(),
					   controlName);
		}
	    ADAParser::ConstantContext *startCtx = ctx->forStatement()->subrangeType()->constant(0);
	    ADAParser::ConstantContext *endCtx   = ctx->forStatement()->subrangeType()->constant(1);

	    visit(startCtx);
	    visit(endCtx);

	    if (startCtx->type != controlType)  error.flag(TYPE_MISMATCH, startCtx);
	    if (startCtx->type != endCtx->type) error.flag(TYPE_MISMATCH, endCtx);

	}
	else{
		bool hasExit = false;
		int statSize = ctx->statementList()->statement().size();
		for(int i = 0; i < statSize; i++){
			ADAParser::StatementContext *statCtx = ctx->statementList()->statement(i);
			if(statCtx->exitStatement() != nullptr){
				hasExit = true;
			}
		}
		if(!hasExit){
			error.flag(EXPECTED_EXIT, ctx);
		}
	}

	visit(ctx->statementList());
	return nullptr;
}

Object Semantics::visitProcedureCallStatement(
                            ADAParser::ProcedureCallStatementContext *ctx)
{
    ADAParser::ProcedureNameContext *nameCtx = ctx->procedureName();
    ADAParser::ArgumentListContext *listCtx = ctx->argumentList();
    string name = toLowerCase(ctx->procedureName()->getText());
    SymtabEntry *procedureId = symtabStack->lookup(name);
    bool badName = false;

    if (procedureId == nullptr)
    {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    }
    else if (procedureId->getKind() != PROCEDURE)
    {
        error.flag(NAME_MUST_BE_PROCEDURE, nameCtx);
        badName = true;
    }

    // Bad procedure name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (ADAParser::ArgumentContext *exprCtx : listCtx->argument())
        {
            visit(exprCtx);
        }
    }

    // Good procedure name.
    else
    {
        vector<SymtabEntry *> *parms = procedureId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
    }

    nameCtx->entry = procedureId;
    return nullptr;
}

Object Semantics::visitFunctionCallFactor(
                                ADAParser::FunctionCallFactorContext *ctx)
{
    ADAParser::FunctionCallContext *callCtx = ctx->functionCall();
    ADAParser::FunctionNameContext *nameCtx = callCtx->functionName();
    ADAParser::ArgumentListContext *listCtx = callCtx->argumentList();
    string name = toLowerCase(callCtx->functionName()->getText());
    SymtabEntry *functionId = symtabStack->lookup(name);
    bool badName = false;

    ctx->type = Predefined::integerType;

    if (functionId == nullptr)
    {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    }
    else if (functionId->getKind() != FUNCTION)
    {
        error.flag(NAME_MUST_BE_FUNCTION, nameCtx);
        badName = true;
    }

    // Bad function name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (ADAParser::ArgumentContext *exprCtx : listCtx->argument())
        {
            visit(exprCtx);
        }
    }

    // Good function name.
    else
    {
        vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
        ctx->type = functionId->getType();
    }

    nameCtx->entry = functionId;
    nameCtx->type  = ctx->type;

    return nullptr;
}

void Semantics::checkCallArguments(
        ADAParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *parms)
{
    int parmsCount = parms->size();
    int argsCount = listCtx != nullptr ? listCtx->argument().size() : 0;

    if (parmsCount != argsCount)
    {
        error.flag(ARGUMENT_COUNT_MISMATCH, listCtx);
        return;
    }

    // Check each argument against the corresponding parameter.
    for (int i = 0; i < parmsCount; i++)
    {
        ADAParser::ArgumentContext *argCtx = listCtx->argument()[i];
        ADAParser::ExpressionContext *exprCtx = argCtx->expression();
        visit(exprCtx);

        SymtabEntry *parmId = (*parms)[i];
        Typespec *parmType = parmId->getType();
        Typespec *argType  = exprCtx->type;

        // For a VAR parameter, the argument must be a variable
        // with the same datatype.
        if (parmId->getKind() == REFERENCE_PARAMETER)
        {
            if (expressionIsVariable(exprCtx))
            {
                if (parmType != argType)
                {
                    error.flag(TYPE_MISMATCH, exprCtx);
                }
            }
            else
            {
                error.flag(ARGUMENT_MUST_BE_VARIABLE, exprCtx);
            }
        }

        // For a value parameter, the argument type must be
        // assignment compatible with the parameter type.
        else if (!TypeChecker::areAssignmentCompatible(parmType, argType))
        {
            error.flag(TYPE_MISMATCH, exprCtx);
        }
    }
}

bool Semantics::expressionIsVariable(ADAParser::ExpressionContext *exprCtx)
{
    // Only a single simple expression?
    if (exprCtx->simpleExpression().size() == 1)
    {
        ADAParser::SimpleExpressionContext *simpleCtx =
                                                exprCtx->simpleExpression()[0];
        // Only a single term?
        if (simpleCtx->term().size() == 1)
        {
            ADAParser::TermContext *termCtx = simpleCtx->term()[0];

            // Only a single factor?
            if (termCtx->factor().size() == 1)
            {
                return dynamic_cast<ADAParser::VariableFactorContext *>(
                                            termCtx->factor()[0]) != nullptr;
            }
        }
    }

    return false;
}

Object Semantics::visitExpression(ADAParser::ExpressionContext *ctx)
{
    ADAParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];

    // First simple expression.
    visit(simpleCtx1);

    Typespec *simpleType1 = simpleCtx1->type;
    ctx->type = simpleType1;

    ADAParser::RelOpContext *relopCtx = ctx->relOp();

    // Second simple expression?
    if (relopCtx != nullptr)
    {
        ADAParser::SimpleExpressionContext *simpleCtx2 =
                                                    ctx->simpleExpression()[1];
        visit(simpleCtx2);

        Typespec *simpleType2 = simpleCtx2->type;
        if (!TypeChecker::areComparisonCompatible(simpleType1, simpleType2))
        {
            error.flag(INCOMPATIBLE_COMPARISON, ctx);
        }

        ctx->type = Predefined::booleanType;
    }

    return nullptr;
}

Object Semantics::visitSimpleExpression(
                                    ADAParser::SimpleExpressionContext *ctx)
{
    int count = ctx->term().size();
    ADAParser::SignContext *signCtx = ctx->sign();
    bool hasSign = signCtx != nullptr;
    ADAParser::TermContext *termCtx1 = ctx->term()[0];

    if (hasSign)
    {
        string sign = signCtx->getText();
        if ((sign== "+") && (sign == "-"))
        {
            error.flag(INVALID_SIGN, signCtx);
        }
    }

    // First term.
    visit(termCtx1);
    Typespec *termType1 = termCtx1->type;

    // Loop over any subsequent terms.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        ADAParser::TermContext *termCtx2 = ctx->term()[i];
        visit(termCtx2);
        Typespec *termType2 = termCtx2->type;

        // Both operands bool ==> bool result. Else type mismatch.
        if (op == "or")
        {
            if (!TypeChecker::isBoolean(termType1))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx1);
            }
            if (!TypeChecker::isBoolean(termType2))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx2);
            }
            if (hasSign)
            {
                error.flag(INVALID_SIGN, signCtx);
            }

            termType2 = Predefined::booleanType;
        }
        else if (op == "+")
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

            // Both operands string ==> string result
            else if (TypeChecker::areBothString(termType1, termType2))
            {
                if (hasSign) error.flag(INVALID_SIGN, signCtx);
                termType2 = Predefined::stringType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }
        else  // -
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }

        termType1 = termType2;
    }

    ctx->type = termType1;
    return nullptr;
}

Object Semantics::visitTerm(ADAParser::TermContext *ctx)
{
    int count = ctx->factor().size();
    ADAParser::FactorContext *factorCtx1 = ctx->factor()[0];

    // First factor.
    visit(factorCtx1);
    Typespec *factorType1 = factorCtx1->type;

    // Loop over any subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        ADAParser::FactorContext *factorCtx2 = ctx->factor()[i];
        visit(factorCtx2);
        Typespec *factorType2 = factorCtx2->type;

        if (op == "*")
        {
            // Both operands integer  ==> integer result
            if (TypeChecker::areBothInteger(factorType1, factorType2))
            {
                factorType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if (op == "/")
        {
            // All integer and real operand combinations ==> real result
            if (   TypeChecker::areBothInteger(factorType1, factorType2)
                || TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if ((op == "div") ||(op == "mod"))
        {
            // Both operands integer ==> integer result. Else type mismatch.
            if (!TypeChecker::isInteger(factorType1))
            {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx1);
                factorType2 = Predefined::integerType;
            }
            if (!TypeChecker::isInteger(factorType2))
            {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx2);
                factorType2 = Predefined::integerType;
            }

            ctx->type = Predefined::integerType;
        }
        else if (op == "and")
        {
            // Both operands bool ==> bool result. Else type mismatch.
            if (!TypeChecker::isBoolean(factorType1))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx1);
                factorType2 = Predefined::booleanType;
            }
            if (!TypeChecker::isBoolean(factorType2))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx2);
                factorType2 = Predefined::booleanType;
            }
        }

        factorType1 = factorType2;
    }

    ctx->type = factorType1;
    return nullptr;
}

Object Semantics::visitVariableFactor(ADAParser::VariableFactorContext *ctx)
{
    ADAParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitVariable(ADAParser::VariableContext *ctx)
{
    ADAParser::VariableIdentifierContext *varIdCtx =
                                                    ctx->variableIdentifier();

    visit(varIdCtx);
    ctx->entry = varIdCtx->entry;
    ctx->type  = variableDatatype(ctx, varIdCtx->type);

    return nullptr;
}

Object Semantics::visitVariableIdentifier(
                                ADAParser::VariableIdentifierContext *ctx)
{

    string variableName = toLowerCase(ctx->IDENTIFIER()->getText());
    SymtabEntry *variableId = symtabStack->lookup(variableName);

    if (variableId != nullptr)
    {
        int lineNumber = ctx->getStart()->getLine();
        ctx->type = variableId->getType();
        ctx->entry = variableId;
        variableId->appendLineNumber(lineNumber);

        Kind kind = variableId->getKind();
        switch (kind)
        {
            case TYPE:
            case PROGRAM:
            case PROGRAM_PARAMETER:
            case PROCEDURE:
            case UNDEFINED:
                error.flag(INVALID_VARIABLE, ctx);
                break;

            default: break;
        }
    }
    else
    {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    return nullptr;
}

Typespec *Semantics::variableDatatype(ADAParser::VariableContext *varCtx,
                                      Typespec *varType)
{
    Typespec *type = varType;

    for (ADAParser::ModifierContext *modCtx : varCtx->modifier())
    {
        // Subscripts.
        if (modCtx->indexList() != nullptr)
        {
            ADAParser::IndexListContext *indexListCtx = modCtx->indexList();

            // Loop over the subscripts.
            for (ADAParser::IndexContext *indexCtx : indexListCtx->index())
            {
                if (type->getForm() == ARRAY)
                {
                    Typespec *indexType = type->getArrayIndexType();
                    ADAParser::ExpressionContext *exprCtx =
                                                        indexCtx->expression();
                    visit(exprCtx);

                    if (indexType->baseType() != exprCtx->type->baseType())
                    {
                        error.flag(TYPE_MISMATCH, exprCtx);
                    }

                    // Datatype of the next dimension.
                    type = type->getArrayElementType();
                }
                else
                {
                    error.flag(TOO_MANY_SUBSCRIPTS, indexCtx);
                }
            }
        }
        else // Record field.
        {
            if (type->getForm() == RECORD)
            {
                Symtab *symtab = type->getRecordSymtab();
                ADAParser::FieldContext *fieldCtx = modCtx->field();
                string fieldName =
                                toLowerCase(fieldCtx->IDENTIFIER()->getText());
                SymtabEntry *fieldId = symtab->lookup(fieldName);

                if (fieldId != nullptr)
                {
                    type = fieldId->getType();
                    fieldCtx->entry = fieldId;
                    fieldCtx->type = type;
                    fieldId->appendLineNumber(modCtx->getStart()->getLine());
                }
                else
                {
                    error.flag(INVALID_FIELD, modCtx);
                }
            }

            // Not a record variable.
            else
            {
                error.flag(INVALID_FIELD, modCtx);
            }
        }
    }

    return type;
}

Object Semantics::visitNumberFactor(ADAParser::NumberFactorContext *ctx)
{
    ADAParser::NumberContext          *numberCtx   = ctx->number();
    ADAParser::UnsignedNumberContext  *unsignedCtx = numberCtx->unsignedNumber();
    ADAParser::IntegerConstantContext *integerCtx  = unsignedCtx->integerConstant();

    ctx->type = (integerCtx != nullptr) ? Predefined::integerType
                                        : Predefined::realType;

    return nullptr;
}

Object Semantics::visitCharacterFactor(ADAParser::CharacterFactorContext *ctx)
{
    ctx->type = Predefined::charType;
    return nullptr;
}

Object Semantics::visitStringFactor(ADAParser::StringFactorContext *ctx)
{
    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitNotFactor(ADAParser::NotFactorContext *ctx)
{
    ADAParser::FactorContext *factorCtx = ctx->factor();
    visit(factorCtx);

    if (factorCtx->type != Predefined::booleanType)
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx);
    }

    ctx->type = Predefined::booleanType;
    return nullptr;
}

Object Semantics::visitParenthesizedFactor(
                                ADAParser::ParenthesizedFactorContext *ctx)
{
    ADAParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}

} // namespace frontend
