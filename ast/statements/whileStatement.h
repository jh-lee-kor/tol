#ifndef TOLELOM_WHILESTATEMENT_H
#define TOLELOM_WHILESTATEMENT_H

#include "statement.h"
#include "blockStatement.h"
#include "../expressions/expression.h"

class WhileStatement : public Statement{
public:
	Token* token{};
	Expression* condition{};

	BlockStatement* loopBody{};

	string String() override {
		return "while: " + condition->String() + " " + "{\n" + loopBody->String() + "}";;
	}
};

#endif //TOLELOM_WHILESTATEMENT_H
