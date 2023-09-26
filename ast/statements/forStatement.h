//
// Created by 이장호 on 2023/09/26.
//

#ifndef TOLELOM_WHILESTATEMENT_H
#define TOLELOM_WHILESTATEMENT_H

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

#endif //TOLELOM_WHILESTATEMENT_H
