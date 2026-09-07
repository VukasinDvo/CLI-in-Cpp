//
// Created by vladi on 8/22/2026.
//

#ifndef OOP1PROJEKAT_PARSEDCOMMAND_H
#define OOP1PROJEKAT_PARSEDCOMMAND_H
#include <optional>
#include <string>
#include <vector>

struct ParsedCommand {
    std::string name;
    std::string option;
    std::optional<std::string> argument;
    bool isQuoted=false;
    std::vector<std::string> extraArguments;
};
#endif //OOP1PROJEKAT_PARSEDCOMMAND_H