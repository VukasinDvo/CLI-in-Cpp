//
// Created by vladi on 8/19/2026.
//
#include "Tokenizer.h"

#include "TokenType.h"

Tokenizer::Tokenizer(const std::string &line): line(line),pos(0) {}

char Tokenizer::peekNextChar() {
    return (pos+1 <line.size()) ? line[pos+1]:'\0';
}

void Tokenizer::skipWhitespace() {
    while (pos<line.size() && std::isspace(line[pos])) pos++;
}

bool Tokenizer::isSpecialChar(char c) {
    return c== '|' || c== '<' || c== '>';
}

std::string Tokenizer::readQuotedString(char quote) {
    std::string result;
    pos++;
    while (pos < line.size() && line[pos] != quote) {
        bool isEscape = (quote == '"' && line[pos] == '\\' && peekNextChar() &&
                          (peekNextChar() == '"' || peekNextChar() == '\\'));

        if (isEscape) {
            result += line[pos + 1];
            pos += 2;
        } else {
            result += line[pos++];
        }
    }
    return result;

}

std::string Tokenizer::readWord() {
    std::string result;
    while (pos<line.size()) {
        char c=line[pos];
        if (isSpecialChar(c)|| std::isspace(c)) {
            break;
        }
        if (c=='"'||c=='\'') {
            result +=readQuotedString(c);
            continue;
        }
        if (c == '\\' && pos + 1 < line.size()) {
            result += line[pos + 1];
            pos += 2;
            continue;
        }


        result += c;
        pos++;



    }
    return result;
}

std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> tokens;
    while (true) {
        skipWhitespace();
        if (pos >= line.size()) break;
        char c = line[pos];
        if (c == '|') { tokens.push_back({TokenType::PIPE, "|", false});
            pos++;
            continue; }
        if (c == '>') {
            if (peekNextChar() == '>') {
                tokens.push_back({TokenType::REDIRECT_APPEND, ">>", false});
                pos += 2;
            } else {
                tokens.push_back({TokenType::REDIRECT_OUT, ">", false});
                pos++;
            }
            continue;
        }
        if (c == '<') { tokens.push_back({TokenType::REDIRECT_IN,
            "<", false});
            pos++;
            continue; }

        bool wasQuoted = (c == '"' || c == '\'');
        tokens.push_back({TokenType::WORD, readWord(), wasQuoted});
    }
    tokens.push_back({TokenType::END, "", false});
    return tokens;
}
