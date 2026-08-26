//
// Created by vladi on 8/19/2026.
//

#include "Parser.h"

#include "Tokenizer.h"
#include "../Command/BaseCommand.h"
#include "../Command/PipelineCommand.h"
#include "../CommandFactory/CommandFactory.h"
#include "../Exeptions/ParseExeptions.h"

Parser::Parser(CommandFactory& factory)
    : factory_(factory), pos(0) {}

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
    ParsedCommand parsed = parseCommandBody();
    return factory.create(parsed);
}

ParsedCommand Parser::parseCommandBody() {
    if (!check(TokenType::WORD)) {
        throw ParseExeptions("Ocekivan naziv komande");
    }

    ParsedCommand cmd;
    cmd.name = peek().text;
    advance();

    // opciona opcija, oblika "-nesto" (npr. -w, -c, -n10)
    if (check(TokenType::WORD) && !peek().text.empty() && peek().text[0] == '-') {
        cmd.option = peek().text.substr(1); // bez '-' na pocetku
        advance();
    }

    // opcioni argument
    if (check(TokenType::WORD)) {
        cmd.argument = peek().text;
        cmd.isQuoted = peek().quoted;
        advance();
    }

    return cmd;
}