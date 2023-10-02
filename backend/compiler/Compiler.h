#ifndef COMPILER_H_
#define COMPILER_H_

#include "ADABaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "ProgramGenerator.h"
#include "StatementGenerator.h"
#include "ExpressionGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class CodeGenerator;

class Compiler : public ADABaseVisitor
{
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    string programName;      // the program name

    CodeGenerator       *code;            // base code generator
    ProgramGenerator    *programCode;     // program code generator
    StatementGenerator  *statementCode;   // statement code generator
    ExpressionGenerator *expressionCode;  // expression code generator

public:
    /**
     * Constructor for the base compiler.
     * @param programId the symtab entry for the program name.
     */
    Compiler(SymtabEntry *programId)
        : programId(programId), programName(programId->getName()),
          code(new CodeGenerator(programName, "j", this)),
          programCode(nullptr), statementCode(nullptr),
          expressionCode(nullptr) {}

    /**
     * Constructor for child compilers of procedures and functions.
     * @param parent the parent compiler.
     */
    Compiler(Compiler *parent)
        : programId(parent->programId), programName(parent->programName),
          code(parent->code), programCode(parent->programCode),
          statementCode(nullptr), expressionCode(nullptr) {}

    /**
     * Constructor for child compilers of records.
     * @param parent the parent compiler.
     * @param recordId the symbol table entry of the name of the record to compile.
     */
    Compiler(Compiler *parent, SymtabEntry *recordId)
    {
        string recordTypePath = recordId->getType()->getRecordTypePath();
        code = new CodeGenerator(recordTypePath, "j", this);
        createNewGenerators(code);

        programCode->emitRecord(recordId, recordTypePath);
    }

    /**
     * Get the name of the object (Jasmin) file.
     * @return the file name.
     */
    string getObjectFileName() { return code->getObjectFileName(); }

    Object visitProgram(ADAParser::ProgramContext *ctx) override;
    Object visitSubprogramBody(ADAParser::SubprogramBodyContext *ctx) override;
    Object visitStatement(ADAParser::StatementContext *ctx) override;
    Object visitAssignmentStatement(ADAParser::AssignmentStatementContext *ctx) override;
    Object visitIfStatement(ADAParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(ADAParser::CaseStatementContext *ctx) override;
    Object visitLoopStatement(ADAParser::LoopStatementContext *ctx) override;
    Object visitProcedureCallStatement(ADAParser::ProcedureCallStatementContext *ctx) override;
    Object visitExpression(ADAParser::ExpressionContext *ctx) override;
    Object visitVariableFactor(ADAParser::VariableFactorContext *ctx) override;
    Object visitVariable(ADAParser::VariableContext *ctx) override;
    Object visitNumberFactor(ADAParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(ADAParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(ADAParser::StringFactorContext *ctx) override;
    Object visitFunctionCallFactor(ADAParser::FunctionCallFactorContext *context) override;
    Object visitNotFactor(ADAParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(ADAParser::ParenthesizedFactorContext *ctx) override;
    Object visitGetStatement(ADAParser::GetStatementContext *ctx) override;
    Object visitGetLineStatement(ADAParser::GetLineStatementContext *ctx) override;
    Object visitPutStatement(ADAParser::PutStatementContext *ctx) override;
    Object visitPutLineStatement(ADAParser::PutLineStatementContext *ctx) override;
    Object visitReturnStatement(ADAParser::ReturnStatementContext *ctx) override;

private:
    /**
     * Create new child code generators.
     * @param parentGenerator the parent code generator.
     */
    void createNewGenerators(CodeGenerator *parentGenerator)
    {
        programCode    = new ProgramGenerator(parentGenerator, this);
        statementCode  = new StatementGenerator(programCode, this);
        expressionCode = new ExpressionGenerator(programCode, this);
    }
};

}}  // namespace backend::compiler

#endif /* COMPILER_H_ */
