#ifndef TOLELOM_VIRTUALMACHINE_H
#define TOLELOM_VIRTUALMACHINE_H

#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "../object/object.h"
#include "../code/code.h"
#include "../compiler/compiler.h"
#include "../endian/endian.h"

class VirtualMachine {
public:
    void testIntegerObject(long long expected, Object* object);
    void run(Bytecode bytecode);


    Object* lastPoppedElement();

    // 디버깅 용으로 public에 나둠 나중에 private로 옮길 것
    vector<Object*> stack;
    int stackPointer;
private:
    vector<Object*> constants;
    vector<Instruction*> instructions;

    // boolean 상수화 (const가 안되네..)
    Boolean* TRUE = new Boolean{true};
    Boolean* FALSE = new Boolean{false};

    const int StackSize = 2048;
    Endian endian;

    Object* stackTop();
    void push(Object* object);
    Object* pop();

    void executeBinaryOperation(OpcodeType opcode);
    void executeBinaryIntegerOperation(OpcodeType opcode, Integer* left, Integer* right);
};


#endif //TOLELOM_VIRTUALMACHINE_H
