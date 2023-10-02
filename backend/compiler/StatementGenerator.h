#ifndef STATEMENTGENERATOR_H_
#define STATEMENTGENERATOR_H_

#include <vector>
#include <map>

#include "CodeGenerator.h"

namespace backend { namespace compiler {

using namespace std;

class StatementGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    StatementGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an assignment statement.
     * @param ctx the AssignmentStatementContext.
     */
    void emitAssignment(ADAParser::AssignmentStatementContext *ctx);

    /**
     * Emit code for an IF statement.
     * @param ctx the IfStatementContext.
     */
    void emitIf(ADAParser::IfStatementContext *ctx);

    /**
     * Emit code for a CASE statement.
     * @param ctx the CaseStatementContext.
     */
    void emitCase(ADAParser::CaseStatementContext *ctx);

    /**
     * Emit code for a LOOP statement.
     * @param ctx the LOOPStatementContext.
     */
    void emitLoop(ADAParser::LoopStatementContext *ctx);

    void emitReturnStatement(ADAParser::ReturnStatementContext *ctx);

    /**
     * Emit code for a procedure call statement.
     * @param ctx the ProcedureCallStatementContext.
     */
    void emitProcedureCall(ADAParser::ProcedureCallStatementContext *ctx);

    /**
     * Emit code for a function call statement.
     * @param ctx the FunctionCallContext.
     */
    void emitFunctionCall(ADAParser::FunctionCallContext *ctx);

    /**
     * Emit code for a PUT statement.
     * @param ctx the PUTStatementContext.
     */
    void emitPut(ADAParser::PutStatementContext *ctx);

    /**
     * Emit code for a PUTLINE statement.
     * @param ctx the PUTLINEStatementContext.
     */
    void emitPutLine(ADAParser::PutLineStatementContext *ctx);

    /**
     * Emit code for a GET statement.
     * @param ctx the GETStatementContext.
     */
    void emitGet(ADAParser::GetStatementContext *ctx);

    /**
     * Emit code for a GETLINE statement.
     * @param ctx the GETLINEStatementContext.
     */
    void emitGetLine(ADAParser::GetLineStatementContext *ctx);

private:
    /**
     * Process the CASE map from the CASE branches.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels.
     * @return the array list of table entries.
     */
    map<int, Label *> *createCaseMap(
                            ADAParser::CaseBranchListContext *branchListCtx,
                            vector<Label *>& branchLabels);

    /**
     * Emit code for the LOOKUPSWITCH instruction.
     * @param entries the table entries.
     * @param branchLabels the branch labels.
     */
    void emitLookupSwitch(map<int, Label *> *labelMap,
                          vector<Label *>& branchLabels);

    /**
     * Emit code for the branch statements.
     * @param branchListCtx the CaseBranchListContext.
     * @param branchLabels the branch labels
     * @throws ADACompilerException if an error occurred.
     */
    void emitBranchStatements(
                            ADAParser::CaseBranchListContext *branchListCtx,
                            vector<Label *>& branchLabels);

    /**
     * Emit a call to a procedure or a function.
     * @param routineId the routine name's symbol table entry.
     * @param argListCtx the ArgumentListContext.
     */
    void emitCall(SymtabEntry *routineId,
                  ADAParser::ArgumentListContext *argListCtx);

    /**
     * Emit code for a call to WRITE or WRITELN.
     * @param argsCtx the WriteArgumentsContext.
     * @param needLF true if need a line feed.
     */
    void emitPut(ADAParser::PutArgumentsContext *argsCtx, bool needLF);

    /**
     * Create the printf format string.
     * @param argsCtx the WriteArgumentsContext.
     * @param format the format string to create.
     * @return the count of expression arguments.
     */
    int createPutFormat(ADAParser::PutArgumentsContext *argsCtx,
                          string& format, bool needLF);

    /**
     * Emit the printf arguments array.
     * @param argsCtx
     * @param exprCount
     */
    void emitArgumentsArray(ADAParser::PutArgumentsContext *argsCtx,
                            int exprCount);

    /**
     * Generate code for a call to READ or READLN.
     * @param argsCtx the ReadArgumentsContext.
     * @param needSkip true if need to skip the rest of the input line.
     */
    void emitGet(ADAParser::GetArgumentsContext *argsCtx, bool needSkip);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
