#ifndef TOLELOM_COMPILER_H
#define TOLELOM_COMPILER_H

#include "../object/object.h"
#include "../code/code.h"
#include "../ast/literals/literal.h"
#include "../ast/literals/booleanLiteral.h"
#include "../ast/literals/functionLiteral.h"
#include "../ast/literals/integerLiteral.h"
#include "../ast/node.h"
#include "../ast/program.h"
#include "../ast/statements/statement.h"
#include "../ast/statements/expressionStatement.h"
#include "../ast/statements/returnStatement.h"
#include "../ast/statements/letStatement.h"
#include "../ast/expressions/integerExpression.h"
#include "../ast/expressions/prefixExpression.h"
#include "../ast/expressions/infixExpression.h"

class Bytecode{
public:
    Instructions instructions;
    vector<Object *> constants;
};

class Compiler{
public:

    Instructions instructions;
    vector<Object *> constants;

    void compile(Node* node);
    int addConstant(Object* obj);
    int emit(Opcode op, const vector<byte> &operands);
    int addInstruction(vector<byte>& ins);
    Bytecode* bytecode();
};


#endif //TOLELOM_COMPILER_H
