#ifndef TOLELOM_FORSTATEMENT_H
#define TOLELOM_FORSTATEMENT_H

#include "statement.h"
#include "blockStatement.h"
#include "../expressions/expression.h"

class ForStatement : public Statement{
public:
	Token* token{};
	Statement* initialization{};
	Expression* condition{};
	Statement* incrementation{};

	BlockStatement* loopBody{};

	string String() override {
		return "while: " + condition->String() + " " + "{\n" + loopBody->String() + "}";;
	}
};

#endif //TOLELOM_FORSTATEMENT_H
