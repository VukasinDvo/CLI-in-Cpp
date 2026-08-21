//
// Created by vladi on 8/19/2026.
//
#include "Tokenizer.h"

#include "TokenType.h"

Tokenizer::Tokenizer(std::string &line): line(line),pos(0) {}

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

std::string Tokenizer::tokenize() {

}
