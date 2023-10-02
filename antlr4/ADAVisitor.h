
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ADA.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "ADAParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ADAParser.
 */
class  ADAVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ADAParser.
   */
    virtual antlrcpp::Any visitProgram(ADAParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHeader(ADAParser::ProgramHeaderContext *context) = 0;

    virtual antlrcpp::Any visitProgramIdentifier(ADAParser::ProgramIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStatementIdentifier(ADAParser::StatementIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ADAParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(ADAParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitConstantsPart(ADAParser::ConstantsPartContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinitionsList(ADAParser::ConstantDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinition(ADAParser::ConstantDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitConstantIdentifier(ADAParser::ConstantIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitConstant(ADAParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitSign(ADAParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitTypesPart(ADAParser::TypesPartContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinitionsList(ADAParser::TypeDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinition(ADAParser::TypeDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(ADAParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpleTypespec(ADAParser::SimpleTypespecContext *context) = 0;

    virtual antlrcpp::Any visitArrayTypespec(ADAParser::ArrayTypespecContext *context) = 0;

    virtual antlrcpp::Any visitRecordTypespec(ADAParser::RecordTypespecContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifierTypespec(ADAParser::TypeIdentifierTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationTypespec(ADAParser::EnumerationTypespecContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeTypespec(ADAParser::SubrangeTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationType(ADAParser::EnumerationTypeContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationConstant(ADAParser::EnumerationConstantContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeType(ADAParser::SubrangeTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(ADAParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayDimensionList(ADAParser::ArrayDimensionListContext *context) = 0;

    virtual antlrcpp::Any visitRecordType(ADAParser::RecordTypeContext *context) = 0;

    virtual antlrcpp::Any visitRecordFields(ADAParser::RecordFieldsContext *context) = 0;

    virtual antlrcpp::Any visitVariablesPart(ADAParser::VariablesPartContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationsList(ADAParser::VariableDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarations(ADAParser::VariableDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifierList(ADAParser::VariableIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifier(ADAParser::VariableIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitSubprogramPart(ADAParser::SubprogramPartContext *context) = 0;

    virtual antlrcpp::Any visitSubprogramBody(ADAParser::SubprogramBodyContext *context) = 0;

    virtual antlrcpp::Any visitProcedureHead(ADAParser::ProcedureHeadContext *context) = 0;

    virtual antlrcpp::Any visitFunctionHead(ADAParser::FunctionHeadContext *context) = 0;

    virtual antlrcpp::Any visitRoutineIdentifier(ADAParser::RoutineIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitParameters(ADAParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarationsList(ADAParser::ParameterDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarations(ADAParser::ParameterDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifierList(ADAParser::ParameterIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifier(ADAParser::ParameterIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ADAParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(ADAParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(ADAParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(ADAParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(ADAParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(ADAParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitLhs(ADAParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhs(ADAParser::RhsContext *context) = 0;

    virtual antlrcpp::Any visitNewLineStatement(ADAParser::NewLineStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(ADAParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitTrueStatementList(ADAParser::TrueStatementListContext *context) = 0;

    virtual antlrcpp::Any visitFalseStatementList(ADAParser::FalseStatementListContext *context) = 0;

    virtual antlrcpp::Any visitElseStatementList(ADAParser::ElseStatementListContext *context) = 0;

    virtual antlrcpp::Any visitIfCondition(ADAParser::IfConditionContext *context) = 0;

    virtual antlrcpp::Any visitElsifCondition(ADAParser::ElsifConditionContext *context) = 0;

    virtual antlrcpp::Any visitExitStatement(ADAParser::ExitStatementContext *context) = 0;

    virtual antlrcpp::Any visitLoopStatement(ADAParser::LoopStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(ADAParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranchList(ADAParser::CaseBranchListContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranch(ADAParser::CaseBranchContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstantList(ADAParser::CaseConstantListContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstant(ADAParser::CaseConstantContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(ADAParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(ADAParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureCallStatement(ADAParser::ProcedureCallStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureName(ADAParser::ProcedureNameContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(ADAParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitArgument(ADAParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitPutStatement(ADAParser::PutStatementContext *context) = 0;

    virtual antlrcpp::Any visitPutLineStatement(ADAParser::PutLineStatementContext *context) = 0;

    virtual antlrcpp::Any visitPutArguments(ADAParser::PutArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitPutArgument(ADAParser::PutArgumentContext *context) = 0;

    virtual antlrcpp::Any visitFieldWidth(ADAParser::FieldWidthContext *context) = 0;

    virtual antlrcpp::Any visitDecimalPlaces(ADAParser::DecimalPlacesContext *context) = 0;

    virtual antlrcpp::Any visitGetStatement(ADAParser::GetStatementContext *context) = 0;

    virtual antlrcpp::Any visitGetLineStatement(ADAParser::GetLineStatementContext *context) = 0;

    virtual antlrcpp::Any visitGetArguments(ADAParser::GetArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ADAParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(ADAParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(ADAParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallFactor(ADAParser::FunctionCallFactorContext *context) = 0;

    virtual antlrcpp::Any visitVariableFactor(ADAParser::VariableFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumberFactor(ADAParser::NumberFactorContext *context) = 0;

    virtual antlrcpp::Any visitCharacterFactor(ADAParser::CharacterFactorContext *context) = 0;

    virtual antlrcpp::Any visitStringFactor(ADAParser::StringFactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(ADAParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedFactor(ADAParser::ParenthesizedFactorContext *context) = 0;

    virtual antlrcpp::Any visitVariable(ADAParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitModifier(ADAParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndexList(ADAParser::IndexListContext *context) = 0;

    virtual antlrcpp::Any visitIndex(ADAParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitField(ADAParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(ADAParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(ADAParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitNumber(ADAParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(ADAParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConstant(ADAParser::IntegerConstantContext *context) = 0;

    virtual antlrcpp::Any visitRealConstant(ADAParser::RealConstantContext *context) = 0;

    virtual antlrcpp::Any visitCharacterConstant(ADAParser::CharacterConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(ADAParser::StringConstantContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(ADAParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(ADAParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(ADAParser::MulOpContext *context) = 0;


};

