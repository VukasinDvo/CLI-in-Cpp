#include "Parser.h"
//
// Created by vladi on 8/19/2026.
//
BaseCommand* Parser::parseCmd(const std::string& line) {
    Tokenizer tokenizer(line);
    tokens_ = tokenizer.tokenize();
    pos_ = 0;

    return parsePipeline();
}

const Token& Parser::peek() const {
    return tokens_[pos_];
}

bool Parser::check(TokenType t) const {
    return peek().type == t;
}

void Parser::advance() {
    if (pos_ < tokens_.size() - 1) {
        pos_++;
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

