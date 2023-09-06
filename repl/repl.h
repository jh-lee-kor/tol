#ifndef TOLELOM_REPL_H
#define TOLELOM_REPL_H

#include <iostream>
#include <exception>
#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "../evaluator/evaluator.h"
#include "../token/tokenType.h"
using namespace std;

class Repl {
public:
    Repl();

    void run();
    void parserTest();
    void lexerTest();
private:
    Lexer lexer;
    Parser parser;
    Evaluator evaluator;
    static std::string printTokenType(TokenType tokenType) {
        switch (tokenType) {
            case TokenType::ILLEGAL:
                return "ILLEGAL";
            case TokenType::END_OF_FILE:
                return "END OF FILE";
            case TokenType::NEW_LINE:
                return "NEW LINE";
            case TokenType::IDENTIFIER:
                return "IDENTIFIER";
            case TokenType::INTEGER:
                return "INTEGER";
            case TokenType::SPACE:
                return "SPACE";

            case TokenType::PLUS:
                return "PLUS";
            case TokenType::MINUS:
                return "MINUS";
            case TokenType::ASTERISK:
                return "ASTERISK";
            case TokenType::SLASH:
                return "SLASH";
            case TokenType::ASSIGN:
                return "ASSIGN";
            case TokenType::EQUAL:
                return "EQUAL";
            case TokenType::NOT_EQUAL:
                return "NOT_EQUAL";
            case TokenType::BANG:
                return "BANG";
            case TokenType::LPAREN:
                return "LPAREN";
            case TokenType::RPAREN:
                return "RPAREN";
            case TokenType::LESS_THAN:
                return "LESS_THAN";

            case TokenType::INT:
                return "INT";
            case TokenType::LET:
                return "LET";
            case TokenType::RETURN:
                return "RETURN";
            case TokenType::TRUE:
                return "TRUE";
            case TokenType::FALSE:
                return "FALSE";
        }
        return "??";
    }

};



#endif //TOLELOM_REPL_H
