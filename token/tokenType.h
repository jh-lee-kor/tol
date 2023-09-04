#ifndef TOLELOM_TOKENTYPE_H
#define TOLELOM_TOKENTYPE_H

enum class TokenType {
    ILLEGAL,
    END_OF_FILE,
    NEW_LINE,
    IDENTIFIER, // 사과
    INTEGER,    // 1, 2, 3
    PLUS,       // +
    MINUS,      // -
    ASTERISK,   // *
    SLASH,      // /
    ASSIGN,     // =
    EQUAL,      // ==
    SPACE,      // ' '
    BANG,       // !
    LPAREN,     // (
    RPAREN,     // )

    // 예약어
    INT,        // 정수
};

#endif //TOLELOM_TOKENTYPE_H
