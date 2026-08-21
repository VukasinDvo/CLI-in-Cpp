//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_BASECOMMAND_H
#define OOP1PROJEKAT_BASECOMMAND_H
#include <string>
#include <vector>

class BaseCommand {
    public:
    explicit BaseCommand(std::vector<std::string> args);
    virtual ~BaseCommand() = default;
    virtual void execute() = 0;

    protected:
    std::vector<std::string> args;

};
#endif //OOP1PROJEKAT_BASECOMMAND_H