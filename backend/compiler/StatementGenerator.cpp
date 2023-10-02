#include <string>
#include <vector>
#include <map>

#include "ADABaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void StatementGenerator::emitAssignment(ADAParser::AssignmentStatementContext *ctx)
{
    ADAParser::VariableContext *varCtx  = ctx->lhs()->variable();
    ADAParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    ADAParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target variable.
    // The target variable has no subscripts or fields.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

    // The target variable is a field.
    else if (lastModCtx->field() != nullptr)
    {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    }

    // The target variable is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(ADAParser::IfStatementContext *ctx)
{
	Label *ifExitLabel = new Label();
	//Label *ElsIfbranchLabel = new Label();
//	Label *ElsIfExitLabel = new Label();
	Label *trueLabel = new Label();

	int size = ctx->elseStatementList().size();
	Label *elsifLabel[size];

	for(int i=0; i<size; i++){
		elsifLabel[i] = new Label();
	}

	compiler->visit(ctx->ifCondition()->expression());
	emit(IFNE, trueLabel);

	for(int i=0; i<size; i++){
		compiler->visit(ctx->elsifCondition(i)->expression());
		emit(IFNE, elsifLabel[i]);
	}

	if(ctx->ELSE() != nullptr){
		compiler->visit(ctx->falseStatementList());
	}
	emit(GOTO, ifExitLabel);

	emitLabel(trueLabel);
	compiler->visit(ctx->trueStatementList());
	emit(GOTO, ifExitLabel);

	for(int i=0; i<size;i++){
		emitLabel(elsifLabel[i]);
		compiler->visit(ctx->elseStatementList(i));
		emit(GOTO, ifExitLabel);
	}

	emitLabel(ifExitLabel);
}

void StatementGenerator::emitCase(ADAParser::CaseStatementContext *ctx)
{
	Label *caseExitLabel = new Label();

	ADAParser::ExpressionContext *exprCtx = ctx->expression();
	int branchSize = 0;
	for(int i=0; i<ctx->caseBranchList()->caseBranch().size(); i++){
		if(ctx->caseBranchList()->caseBranch(i)->caseConstantList() == nullptr) break;
		branchSize++;
	}
	Label *branchLabel[branchSize];

	for(int i=0; i<branchSize; i++){
		branchLabel[i] = new Label();

	}

	for(int i=0; i<branchSize; i++){
		ADAParser::CaseBranchContext *branCtx = ctx->caseBranchList()->caseBranch(i);
		int constSize = branCtx->caseConstantList()->caseConstant().size();

		for(int j = 0; j<constSize; j++){
			compiler->visit(exprCtx);
			ADAParser::CaseConstantContext *caseConCtx = branCtx->caseConstantList()->caseConstant(j);
			Typespec *caseConType  = caseConCtx->type;

			if(caseConType == Predefined::integerType){
				int value = stoi(caseConCtx->getText());
				emitLoadConstant(value);
			}else if(caseConType == Predefined::charType){
				int value = caseConCtx->constant()->value.as<char>();
				emitLoadConstant(value);
			}else{

			}

			emit(IF_ICMPEQ,branchLabel[i]);
		}
	}

	emit(GOTO, caseExitLabel);


	for(int i=0; i<branchSize; i++){

		emitLabel(branchLabel[i]);

		compiler->visit(ctx->caseBranchList()->caseBranch(i)->statement());
		emit(GOTO, caseExitLabel);
	}

	emitLabel(caseExitLabel);
}

void StatementGenerator::emitLoop(ADAParser::LoopStatementContext *ctx)
{
	 Label *loopTopLabel  = new Label();
	 Label *loopExitLabel = new Label();

	 if(ctx->forStatement()!=nullptr){
		ADAParser::VariableContext *varCtx  = ctx->forStatement()->variable();
		ADAParser::SubrangeTypeContext *ranCtx = ctx->forStatement()->subrangeType();
		SymtabEntry *varId = varCtx->entry;

		ADAParser::ConstantContext *ConCtx0 = ranCtx->constant(0);
		ADAParser::ConstantContext *ConCtx1 = ranCtx->constant(1);
		Typespec *ConType  = ConCtx0->type;

		if(ConType == Predefined::integerType){
			if(ctx->forStatement()->REVERSE()!=nullptr)
				emitLoadConstant(stoi(ConCtx1->getText()));
			else
				emitLoadConstant(stoi(ConCtx0->getText()));

		}else if(ConType == Predefined::charType){
			if(ctx->forStatement()->REVERSE()!=nullptr)
				emitLoadConstant(ConCtx1->value.as<char>());
			else
				emitLoadConstant(ConCtx0->value.as<char>());
		}


		emitStoreValue(varId, varId->getType());
		emitLabel(loopTopLabel);

		emitLoadValue(varId);

		if(ConType == Predefined::integerType){
			if(ctx->forStatement()->REVERSE()!=nullptr){
				emitLoadConstant(stoi(ConCtx0->getText()));
				emit(IF_ICMPLT, loopExitLabel);
			}
			else{
				emitLoadConstant(stoi(ConCtx1->getText()));
				emit(IF_ICMPGT, loopExitLabel);
			}
		}
		else if(ConType == Predefined::charType){
			if(ctx->forStatement()->REVERSE()!=nullptr){
				emitLoadConstant(ConCtx0->value.as<char>());
				emit(IF_ICMPLT, loopExitLabel);
			}

			else{
				emitLoadConstant(ConCtx1->value.as<char>());
				emit(IF_ICMPGT, loopExitLabel);
			}

		}

		for(int i=0;i< ctx->statementList()->statement().size();i++){
			ADAParser::StatementContext *statCtx = ctx->statementList()->statement(i);
			if(statCtx->exitStatement()!= nullptr){
				if(statCtx->exitStatement()->WHEN()!= nullptr){
					compiler->visit(statCtx->exitStatement()->expression());
					emit(IFNE,loopExitLabel);
				}
				else{
					emit(GOTO,loopExitLabel);
				}
			}
			else{
				compiler->visit(statCtx);
			}

		}

		emitLoadValue(varId);
		emit(ICONST_1);

		if(ctx->forStatement()->REVERSE()!=nullptr)
			emit(ISUB);
		else
			emit(IADD);

		emitStoreValue(varId, varId->getType());
	}
	else{
		  if(ctx->whileStatement()!= nullptr){
			  emitLabel(loopTopLabel);
			  compiler->visit(ctx->whileStatement()->expression());
			  emit(IFEQ, loopExitLabel);
		  }
		  else{
		   emitLabel(loopTopLabel);
		  }

		  for(int i=0;i< ctx->statementList()->statement().size();i++){
				ADAParser::StatementContext *statCtx = ctx->statementList()->statement(i);
			  if(statCtx->exitStatement()!= nullptr){
				  if(statCtx->exitStatement()->WHEN()!= nullptr){
					  compiler->visit(statCtx->exitStatement()->expression());
					  emit(IFNE,loopExitLabel);
				  }
				  else{
					  emit(GOTO,loopExitLabel);
				  }
			  }
			  else{
				  compiler->visit(statCtx);
			  }
		 }
	}
	 emit(GOTO, loopTopLabel);
	 emitLabel(loopExitLabel);
}
/*

void StatementGenerator::emitFor(ADAParser::ForStatementContext *ctx)
{
	Label *loopTopLabel  = new Label();
	Label *loopExitLabel = new Label();

	ADAParser::VariableContext *varCtx  = ctx->variable();
	ADAParser::ExpressionContext *exprCtx = ctx->expression(0);
	SymtabEntry *varId = varCtx->entry;

	int modifierCount = varCtx->modifier().size();
	ADAParser::ModifierContext *lastModCtx = modifierCount == 0
							? nullptr : varCtx->modifier()[modifierCount - 1];

	compiler->visit(exprCtx);
	if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

	emitLabel(loopTopLabel);
	emitLoadValue(varId);

	compiler->visit(ctx->expression(1));
	if(ctx->TO()!=nullptr){
		emit(IF_ICMPGT, loopExitLabel);
	}
	else{
		emit(IF_ICMPLT, loopExitLabel);
	}
	compiler->visit(ctx->statement());

	emitLoadValue(varId);
	emit(ICONST_1);

	if(ctx->TO()!= nullptr){
		emit(IADD);
	}
	else
		emit(ISUB);

	emitStoreValue(varId, varId->getType());

	emit(GOTO, loopTopLabel);
	emitLabel(loopExitLabel);
}
*/
void StatementGenerator::emitProcedureCall(ADAParser::ProcedureCallStatementContext *ctx)
{
    SymtabEntry *procId = ctx->procedureName()->entry;
    if(ctx->argumentList()!=nullptr){
    	ADAParser::ArgumentListContext *argListCtx = ctx->argumentList();
    	emitCall(procId,argListCtx);
    }else{
    	string header = programName+ "/"+ ctx->procedureName()->getText() + "()V";
    	emit(INVOKESTATIC, header);
    }
}

void StatementGenerator::emitFunctionCall(ADAParser::FunctionCallContext *ctx)
{
    SymtabEntry *procId = ctx->functionName()->entry;
	if(ctx->argumentList()!=nullptr){
		ADAParser::ArgumentListContext *argListCtx = ctx->argumentList();
		emitCall(procId,argListCtx);
	}else{
		string header = programName+ "/"+ ctx->functionName()->getText() + "()V";
		emit(INVOKESTATIC, header);
	}
}

void StatementGenerator::emitReturnStatement(ADAParser::ReturnStatementContext *ctx){
	compiler->visit(ctx->expression());
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  ADAParser::ArgumentListContext *argListCtx)
{
	string routineName = routineId->getName();
	vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
	string header(routineName +"(");
	int i = 0;

	if (parmIds != nullptr){
		string parmType = "";
		for (SymtabEntry *parmId : *parmIds){
			parmType = typeDescriptor(parmId);
			compiler->visit(argListCtx->argument(i)->expression());
			if(argListCtx->argument(i)->expression()->type == Predefined::integerType){
				if(parmType == "F"){
					emit(I2F);
				}
				else if(parmType == "C"){
					emit(I2C);
				}
				else if(parmType == "D"){
					emit(I2D);
				}
			}
			else if(argListCtx->argument(i)->expression()->type == Predefined::realType){
				if(parmType == "I"){
					emit(F2I);
				}
				else if(parmType == "D"){
					emit(F2D);
				}
			}
			header += typeDescriptor(parmId);
			i++;
		}
	}
	header += ")" + typeDescriptor(routineId);

	string fieldPath = programName + "/" + header;

	emit(INVOKESTATIC, fieldPath);
}

void StatementGenerator::emitPut(ADAParser::PutStatementContext *ctx)
{
    emitPut(ctx->putArguments(), false);
}

void StatementGenerator::emitPutLine(ADAParser::PutLineStatementContext *ctx)
{
    emitPut(ctx->putArguments(), true);
}

void StatementGenerator::emitPut(ADAParser::PutArgumentsContext *argsCtx,
                      bool needLF)
{
    emit(GETSTATIC, "java/lang/System/out", "Ljava/io/PrintStream;");

    // WRITELN with no arguments.
    if (argsCtx == nullptr)
    {
        emit(INVOKEVIRTUAL, "java/io/PrintStream.println()V");
        localStack->decrease(1);
    }

    // Generate code for the arguments.
    else
    {
        string format;
        int exprCount = createPutFormat(argsCtx, format, needLF);

        // Load the format string.
        emit(LDC, format);

        // Emit the arguments array.
       if (exprCount > 0)
        {
            emitArgumentsArray(argsCtx, exprCount);

            emit(INVOKEVIRTUAL,
                        string("java/io/PrintStream/printf(Ljava/lang/String;")
                      + string("[Ljava/lang/Object;)")
                      + string("Ljava/io/PrintStream;"));
            localStack->decrease(2);
            emit(POP);
        }
        else
        {
            emit(INVOKEVIRTUAL,
                 "java/io/PrintStream/print(Ljava/lang/String;)V");
            localStack->decrease(2);
        }
    }
}

int StatementGenerator::createPutFormat(
                                ADAParser::PutArgumentsContext *argsCtx,
                                string& format, bool needLF)
{
    int exprCount = 0;
    format += "\"";

    // Loop over the write arguments.
    for (ADAParser::PutArgumentContext *argCtx : argsCtx->putArgument())
    {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            ADAParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                               && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                ADAParser::DecimalPlacesContext *dpCtx =
                                                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                            : type == Predefined::realType    ? "f"
                            : type == Predefined::booleanType ? "b"
                            : type == Predefined::charType    ? "c"
                            :                                  "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(
                    ADAParser::PutArgumentsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the write arguments to fill the arguments array.
    for (ADAParser::PutArgumentContext *argCtx :
                                                argsCtx->putArgument())
    {
        string argText = argCtx->getText();
        ADAParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\'')
        {
            emit(DUP);
            emitLoadConstant(index++);

            compiler->visit(exprCtx);

            Form form = type->getForm();
            if (    ((form == SCALAR) || (form == ENUMERATION))
                 && (type != Predefined::stringType))
            {
                emit(INVOKESTATIC, valueOfSignature(type));
            }

            // Store the value into the array.
            emit(AASTORE);
        }
    }
}

void StatementGenerator::emitGet(ADAParser::GetStatementContext *ctx)
{
    emitGet(ctx->getArguments(), false);
}

void StatementGenerator::emitGetLine(ADAParser::GetLineStatementContext *ctx)
{
    emitGet(ctx->getArguments(), true);
}

void StatementGenerator::emitGet(ADAParser::GetArgumentsContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        ADAParser::VariableContext *varCtx = argsCtx->variable()[i];
        Typespec *varType = varCtx->type;

        if (varType == Predefined::integerType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextInt()I");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::realType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextFloat()F");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::booleanType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextBoolean()Z");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::charType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(LDC, "\"\"");
            emit(INVOKEVIRTUAL,
                 string("java/util/Scanner/useDelimiter(Ljava/lang/String;)") +
                 string("Ljava/util/Scanner;"));
            emit(POP);
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emit(ICONST_0);
            emit(INVOKEVIRTUAL, "java/lang/String/charAt(I)C");
            emitStoreValue(varCtx->entry, nullptr);

            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/reset()Ljava/util/Scanner;");

        }
        else  // string
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emitStoreValue(varCtx->entry, nullptr);
        }
    }

    // READLN: Skip the rest of the input line.
    if (needSkip)
    {
        emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
        emit(INVOKEVIRTUAL, "java/util/Scanner/nextLine()Ljava/lang/String;");
        emit(POP);
    }
}

}} // namespace backend::compiler
