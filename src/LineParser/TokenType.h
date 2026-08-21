//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_TOKENTYPE_H
#define OOP1PROJEKAT_TOKENTYPE_H
#include <string>


enum class TokenType {
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
};

struct Token {
    TokenType type;
    std::string text;
};

struct Redirection {
    TokenType type;
    std::string target;
};


#endif //OOP1PROJEKAT_TOKENTYPE_H