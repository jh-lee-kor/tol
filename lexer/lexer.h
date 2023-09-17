#ifndef TOLELOM_LEXER_H
#define TOLELOM_LEXER_H

#include <map>
#include <string>
#include <vector>
#include "../token/token.h"
#include "../utf8Converter/utf8Converter.h"

using namespace std;

class Lexer {
public:
    vector<Token*> run(const string &code);
private:
    string input;
    vector<string> characters;
    vector<Token*> tokens;
    Utf8Converter utf8Converter;
    int currentReadPoint;
    int nextReadPoint;
    int indentLevel;

    void initialization();
    static bool isNumber(const std::string &character);
    string readNumber();
    static bool isLetter(const string &character);
    string readLetter();

    map<string, TokenType> keywords = {
            {"정수", TokenType::INT},
            {"변수", TokenType::LET},
            {"리턴", TokenType::RETURN},
            {"true", TokenType::TRUE},
            {"false", TokenType::FALSE},
            {"만약", TokenType::IF},
            {"아니면", TokenType::ELSE},
    };
};




#endif //TOLELOM_LEXER_H
