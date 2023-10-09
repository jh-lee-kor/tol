#ifndef TOLELOM_CODE_H
#define TOLELOM_CODE_H

#include <string>
#include <map>
#include <format>
#include <vector>
using namespace std;

using Instructions = vector<byte>;
// Opcode = unsigned char;

enum class Opcode : unsigned char {
    OpConstant,

};

class Definition {
public:
    string name;
    vector<int> operandWidths;
};

map<Opcode, Definition*> definitions = {
        {Opcode::OpConstant, new Definition{"OpConstant", vector<int>{2}}},
};

Definition* findDefinition(Opcode op);

Instructions makeInstruction(Opcode op, const vector<byte>& operands);

vector<byte> readOperands(Definition* def, Instructions* ins);

#endif //TOLELOM_CODE_H
