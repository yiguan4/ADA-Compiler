#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include <map>

#include "ADABaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "SemanticErrorHandler.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Semantics : public ADABaseVisitor
{
private:
    BackendMode mode;
    SymtabStack *symtabStack;
    SymtabEntry *programId;
    SemanticErrorHandler error;

    map<string, Typespec *> *typeTable;

    /**
     * Return the number of values in a datatype.
     * @param type the datatype.
     * @return the number of values.
     */
    int typeCount(Typespec *type);

    /**
     * Determine whether or not an expression is a variable only.
     * @param exprCtx the ExpressionContext.
     * @return true if it's an expression only, else false.
     */
    bool expressionIsVariable(ADAParser::ExpressionContext *exprCtx);

    /**
     * Perform semantic operations on procedure and function call arguments.
     * @param listCtx the ArgumentListContext.
     * @param parameters the vector of parameters to fill.
     */
    void checkCallArguments(ADAParser::ArgumentListContext *listCtx,
                            vector<SymtabEntry *> *parms);

    /**
     * Determine the datatype of a variable that can have modifiers.
     * @param varCtx the VariableContext.
     * @param varType the variable's datatype without the modifiers.
     * @return the datatype with any modifiers.
     */
    Typespec *variableDatatype(ADAParser::VariableContext *varCtx,
                               Typespec *varType);

    /**
     * Create a new record type.
     * @param recordTypeSpecCtx the RecordTypespecContext.
     * @param recordTypeName the name of the record type.
     * @return the symbol table entry of the record type identifier.
     */
    SymtabEntry *createRecordType(
                        ADAParser::RecordTypespecContext *recordTypeSpecCtx,
                        string recordTypeName);

    /**
     * Create the fully qualified type pathname of a record type.
     * @param recordType the record type.
     * @return the pathname.
     */
    string createRecordTypePath(Typespec *recordType);

    /**
     * Create the symbol table for a record type.
     * @param ctx the RecordFieldsContext,
     * @param ownerId the symbol table entry of the owner's identifier.
     * @return the symbol table.
     */
    Symtab *createRecordSymtab(
                ADAParser::RecordFieldsContext *ctx, SymtabEntry *ownerId);

public:
    Semantics(BackendMode mode) : mode(mode), programId(nullptr)
    {
        // Create and initialize the symbol table stack.
        symtabStack = new SymtabStack();
        Predefined::initialize(symtabStack);

        typeTable = new map<string, Typespec *>();
        (*typeTable)["integer"] 	= Predefined::integerType;
        (*typeTable)["real"]    	= Predefined::realType;
        (*typeTable)["boolean"] 	= Predefined::booleanType;
        (*typeTable)["character"]   = Predefined::charType;
        (*typeTable)["string"]  	= Predefined::stringType;
    }

    /**
     * Get the symbol table entry of the program identifier.
     * @return the entry.
     */
    SymtabEntry *getProgramId() { return programId; }

    /**
     * Get the count of semantic errors.
     * @return the count.
     */
    int getErrorCount() const { return error.getCount(); }

    /**
     * Return the default value for a given datatype.
     * @param type the datatype.
     */
    static Object defaultValue(Typespec *type);

    Object visitProgram(ADAParser::ProgramContext *ctx) override;
    Object visitProgramHeader(ADAParser::ProgramHeaderContext *ctx) override;
    Object visitConstantDefinition(ADAParser::ConstantDefinitionContext *ctx) override;
    Object visitConstant(ADAParser::ConstantContext *ctx) override;
    Object visitTypeDefinition(ADAParser::TypeDefinitionContext *ctx) override;
    Object visitRecordTypespec(ADAParser::RecordTypespecContext *ctx) override;
    Object visitSimpleTypespec(ADAParser::SimpleTypespecContext *ctx) override;
    Object visitTypeIdentifierTypespec(ADAParser::TypeIdentifierTypespecContext *ctx) override;
    Object visitTypeIdentifier(ADAParser::TypeIdentifierContext *ctx) override;
    Object visitEnumerationTypespec(ADAParser::EnumerationTypespecContext *ctx) override;
    Object visitSubrangeTypespec(ADAParser::SubrangeTypespecContext *ctx) override;
    Object visitArrayTypespec(ADAParser::ArrayTypespecContext *ctx) override;
    Object visitVariableDeclarations(ADAParser::VariableDeclarationsContext *ctx) override;
    Object visitSubprogramBody(ADAParser::SubprogramBodyContext *ctx) override;
    Object visitParameterDeclarationsList(ADAParser::ParameterDeclarationsListContext *ctx) override;
    Object visitParameterDeclarations(ADAParser::ParameterDeclarationsContext *ctx) override;
    Object visitAssignmentStatement(ADAParser::AssignmentStatementContext *ctx) override;
    Object visitLhs(ADAParser::LhsContext *ctx) override;
    Object visitIfStatement(ADAParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(ADAParser::CaseStatementContext *ctx) override;
    Object visitLoopStatement(ADAParser::LoopStatementContext *ctx) override;
    Object visitProcedureCallStatement(ADAParser::ProcedureCallStatementContext *ctx) override;
    Object visitFunctionCallFactor(ADAParser::FunctionCallFactorContext *ctx) override;
    Object visitExpression(ADAParser::ExpressionContext *ctx) override;
    Object visitSimpleExpression(ADAParser::SimpleExpressionContext *ctx) override;
    Object visitTerm(ADAParser::TermContext *ctx) override;
    Object visitVariableFactor(ADAParser::VariableFactorContext *ctx) override;
    Object visitVariable(ADAParser::VariableContext *ctx) override;
    Object visitVariableIdentifier(ADAParser::VariableIdentifierContext *ctx) override;
    Object visitNumberFactor(ADAParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(ADAParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(ADAParser::StringFactorContext *ctx) override;
    Object visitNotFactor(ADAParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(ADAParser::ParenthesizedFactorContext *ctx) override;
};

} // namespace frontend

#endif /* SEMANTICS_H_ */
