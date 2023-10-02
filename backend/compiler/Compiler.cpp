#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

Object Compiler::visitProgram(ADAParser::ProgramContext *ctx)
{
    createNewGenerators(code);
    programCode->emitProgram(ctx);
    return nullptr;
}

Object Compiler::visitSubprogramBody(
                                ADAParser::SubprogramBodyContext *ctx)
{
    createNewGenerators(programCode);
    programCode->emitSubprogram(ctx);

    return nullptr;
}

Object Compiler::visitStatement(ADAParser::StatementContext *ctx)
{
    if (   (ctx->compoundStatement() == nullptr)
        && (ctx->emptyStatement() == nullptr))
    {
        statementCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitAssignmentStatement(
                                ADAParser::AssignmentStatementContext *ctx)
{
    statementCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitIfStatement(ADAParser::IfStatementContext *ctx)
{
    statementCode->emitIf(ctx);
    return nullptr;
}

Object Compiler::visitCaseStatement(ADAParser::CaseStatementContext *ctx)
{
    statementCode->emitCase(ctx);
    return nullptr;
}


Object Compiler::visitLoopStatement(ADAParser::LoopStatementContext *ctx)
{
    statementCode->emitLoop(ctx);
    return nullptr;
}



Object Compiler::visitProcedureCallStatement(
                            ADAParser::ProcedureCallStatementContext *ctx)
{
    statementCode->emitProcedureCall(ctx);
    return nullptr;
}

Object Compiler::visitExpression(ADAParser::ExpressionContext *ctx)
{
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitVariableFactor(ADAParser::VariableFactorContext *ctx)
{
    expressionCode->emitLoadValue(ctx->variable());
    return nullptr;
}

Object Compiler::visitVariable(ADAParser::VariableContext *ctx)
{
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitNumberFactor(ADAParser::NumberFactorContext *ctx)
{
    if (ctx->type == Predefined::integerType)
    {
        expressionCode->emitLoadIntegerConstant(ctx->number());
    }
    else
    {
        expressionCode->emitLoadRealConstant(ctx->number());
    }

    return nullptr;
}

Object Compiler::visitCharacterFactor(ADAParser::CharacterFactorContext *ctx)
{
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitStringFactor(ADAParser::StringFactorContext *ctx)
{
    string jasminString = convertString(ctx->getText(), true);
    expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(
                                ADAParser::FunctionCallFactorContext *ctx)
{
    statementCode->emitFunctionCall(ctx->functionCall());
    return nullptr;
}

Object Compiler::visitNotFactor(ADAParser::NotFactorContext *ctx)
{
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedFactor(
                                ADAParser::ParenthesizedFactorContext *ctx)
{
    return visit(ctx->expression());
}

Object Compiler::visitPutStatement(ADAParser::PutStatementContext *ctx)
{
    statementCode->emitPut(ctx);
    return nullptr;
}

Object Compiler::visitPutLineStatement(ADAParser::PutLineStatementContext *ctx)
{
    statementCode->emitPutLine(ctx);
    return nullptr;
}

Object Compiler::visitGetStatement(ADAParser::GetStatementContext *ctx)
{
    statementCode->emitGet(ctx);
    return nullptr;
}

Object Compiler::visitGetLineStatement(ADAParser::GetLineStatementContext *ctx)
{
    statementCode->emitGetLine(ctx);
    return nullptr;
}

Object Compiler::visitReturnStatement(ADAParser::ReturnStatementContext *ctx){
    statementCode->emitReturnStatement(ctx);
    return nullptr;
}

}}  // namespace backend::compiler
