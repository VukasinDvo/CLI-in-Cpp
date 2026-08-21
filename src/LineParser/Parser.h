//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_PARSER_H
#define OOP1PROJEKAT_PARSER_H
#include <string>
#include <vector>
class BaseCommand;

class Parser {
    public:

    BaseCommand* parseCmd(std::string token);

private:
    std::vector<std::string> tokenize(std::string line);


};
#endif //OOP1PROJEKAT_PARSER_H