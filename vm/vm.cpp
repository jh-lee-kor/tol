#include "vm.h"

VM::VM(Bytecode *bytecode) {
    this->instructions = bytecode->instructions;
    this->constants = bytecode->constants;
    this->sp = 0;
}

Object *VM::stackTop() {
    if(sp == 0){
        return nullptr;
    }
    return stack[sp-1];
}

void VM::run() { // ??
    for(int ip = 0; ip < instructions.size(); ip++){
        Opcode op = Opcode(instructions[ip]);
        switch(op){
            case Opcode::OpConstant:
				byte h, l;
				h = this->instructions[ip+1];
				l = this->instructions[ip+2];
        }
    }
}

void VM::push(Object *obj) {
    if(sp >= stackSize){
        throw overflow_error("VM : Stack Overflow");
    }

    stack[sp++] = obj;
}
