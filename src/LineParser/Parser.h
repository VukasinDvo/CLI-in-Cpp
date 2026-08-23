//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_PARSER_H
#define OOP1PROJEKAT_PARSER_H

#include <string>
#include <vector>
#include "TokenType.h"
#include "ParsedCommand.h"

class BaseCommand;
class CommandFactory;

class Parser {
public:
    explicit Parser(CommandFactory& factory);
    BaseCommand* parseCmd(const std::string& line);

private:
    CommandFactory& factory_;
    std::vector<Token> tokens;
    size_t pos;

    BaseCommand* parsePipeline();
    BaseCommand* parseSingleCommand();
    ParsedCommand parseCommandBody();

    const Token& peek() const;
    bool check(TokenType t) const;
    void advance();
};

#endif //OOP1PROJEKAT_PARSER_H