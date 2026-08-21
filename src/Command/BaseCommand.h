//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_BASECOMMAND_H
#define OOP1PROJEKAT_BASECOMMAND_H
#include <string>
#include <vector>

class BaseCommand {
    public:
    virtual ~BaseCommand() = default;
    virtual void execute() = 0;

    private:
    std::vector<std::string> args;

};
#endif //OOP1PROJEKAT_BASECOMMAND_H