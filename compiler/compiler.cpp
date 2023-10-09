#include "compiler.h"

void Compiler::compile(Node *node) {
    if(Program* program = dynamic_cast<Program* >(node)){
        for(auto& s : program->statements){
            compile(s);
        }
    }
    else if(ExpressionStatement* expressionStatement = dynamic_cast<ExpressionStatement*>(node)){
        compile(expressionStatement->expression);
    }
    else if(InfixExpression* infixStatement = dynamic_cast<InfixExpression*>(node)){
        compile(infixStatement->left);
        compile(infixStatement->right);
    }
    else if (IntegerLiteral *integerLiteral = dynamic_cast<IntegerLiteral *>(node)) {
        Integer * integer = new Integer;
        integer->value = integerLiteral->value;
        emit(Opcode::OpConstant, vector<byte>{(byte)addConstant(integer)});
    }


}

Bytecode *Compiler::bytecode() {
    Bytecode* bytecode = new Bytecode;
    bytecode->instructions = this->instructions;
    bytecode->constants = this->constants;
    return bytecode;
}

int Compiler::addConstant(Object* obj) {
    this->constants.push_back(obj);
    return (int)this->constants.size() - 1;
}

int Compiler::emit(Opcode op, const vector<byte> &operands) {
    Instructions instruction = makeInstruction(op, operands);
    int pos = addInstruction(instruction);
    return pos; // 새롭게 만든 명령어의 시작 위치 반환
}

int Compiler::addInstruction(vector<byte> &ins) {
    int posNewInstruction = this->instructions.size();
    for(auto & i : ins){
        instructions.push_back(i);
    }
    return posNewInstruction; // 추가한 명령어의 시작 위치 반환
}

