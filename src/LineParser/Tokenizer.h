//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_TOKENIZER_H
#define OOP1PROJEKAT_TOKENIZER_H
#include <string>
#include <vector>

#include "TokenType.h"

class Tokenizer {
    public:
    explicit Tokenizer(const std::string &line);

    std::vector<Token> tokenize();

    private:
    std::string line;
    size_t pos;

    char peekNextChar();
    void skipWhitespace();
    std::string readWord();
    bool isSpecialChar(char c);
    std::string readQuotedString(char quote);

};
#endif //OOP1PROJEKAT_TOKENIZER_H