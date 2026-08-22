
//
// Created by vladi on 8/19/2026.
//
#include "Parser.h"
#
BaseCommand* Parser::parseCmd(const std::string& line) {
    Tokenizer tokenizer(line);
    tokens = tokenizer.tokenize();
    pos = 0;

    return parsePipeline();
}

const Token& Parser::peek() const {
    return tokens[pos];
}

bool Parser::check(TokenType t) const {
    return peek().type == t;
}

void Parser::advance() {
    if (pos < tokens.size() - 1) {
        pos++;
    }
}

BaseCommand* Parser::parsePipeline() {
    std::vector<BaseCommand*> commands;
    commands.push_back(parseSingleCommand());

    while (check(TokenType::PIPE)) {
        advance();
        commands.push_back(parseSingleCommand());
    }

    if (commands.size() == 1) {
        return commands[0];
    }
    return new PipelineCommand(commands);
}

BaseCommand* Parser::parseSingleCommand() {
    std::vector<std::string> argv;

    while (check(TokenType::WORD)) {
        argv.push_back(peek().text);
        advance();
    }

    if (argv.empty()) {
        throw ParseException("Prazna komanda u pipeline-u");
    }

    return CommandFactory::create(argv);
}

