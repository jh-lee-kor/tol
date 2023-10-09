#ifndef TOLELOM_VM_H
#define TOLELOM_VM_H

#include <vector>
#include "../object/object.h"
#include "../code/code.h"
#include "../compiler/compiler.h"

using namespace std;

const int stackSize = 2048;

class VM{
public:
    vector<Object *> constants;
    Instructions instructions;

    Object * stack[stackSize];
    int sp;

    VM(Bytecode * bytecode);
    Object * stackTop();
    void push(Object * obj);
    void run();
};


#endif //TOLELOM_VM_H
