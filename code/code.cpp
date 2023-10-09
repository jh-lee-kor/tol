#include "code.h"


Instructions makeInstruction(Opcode op, const vector<byte> &operands) {
    Definition* definition = findDefinition(op);

    int instructionLength = 1;
    for(auto& w : definition->operandWidths){
        instructionLength += w;
    }

    Instructions instruction;
    instruction.assign(instructionLength, (byte)0);
    instruction[0] = (byte)op;

    int offset = 1;
    for(int i = 0; i < operands.size(); i++){
        int width = definition->operandWidths[i];
        switch(width){
            case 2:
                instruction[offset] = operands[i]; // big endian ???
        }
        offset += width;
    }

    return instruction;
}

Definition* findDefinition(Opcode op) {
    if (definitions.find(op) != definitions.end()) {
        return definitions.find(op)->second;
    }
    throw invalid_argument("정의된 opcode가 없습니다.");
}

vector<byte> readOperands(Definition *def, Instructions ins) {
    vector<byte> operands(def->operandWidths.size());
    int offset = 0;

    for (int i = 0; i < def->operandWidths.size(); i++) {
        int width = def->operandWidths[i];
        switch (width) {
            case 2:
                operands[i] = ins[offset]; // big endian ???
                break;
        }
        offset += width;
    }

    return operands;
}
