//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_PARSER_H
#define OOP1PROJEKAT_PARSER_H
#include <string>
#include <vector>
#include "Tokenizer.h"
#include "TokenType.h"
class BaseCommand;

class Parser {
    public:
    BaseCommand* parseCmd(std::string token);

private:
    std::vector<Token> tokens;
    size_t pos;

    BaseCommand* parsePipeline(std::string token);
    BaseCommand* parseCommand(std::string token);

    const Token& peek() const;
    bool check(TokenType t) const;
    void advance();


};
#endif //OOP1PROJEKAT_PARSER_H