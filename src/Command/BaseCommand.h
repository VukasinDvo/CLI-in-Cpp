//
// Created by vladi on 8/19/2026.
//

#ifndef OOP1PROJEKAT_BASECOMMAND_H
#define OOP1PROJEKAT_BASECOMMAND_H
#include <functional>
#include <string>
#include <vector>



#include <iostream>
#include <memory>
#include "../LineParser/ParsedCommand.h"


class BaseCommand {
public:
    using FunWraper=std::function<BaseCommand*(ParsedCommand, std::unique_ptr<std::istream>, std::unique_ptr<std::ostream>)>;
    BaseCommand(ParsedCommand parsed,
                std::unique_ptr<std::istream> ownedInput,
                std::unique_ptr<std::ostream> ownedOutput);

    virtual ~BaseCommand() = default;
    virtual void execute() = 0;

protected:
    ParsedCommand parsed;
    std::istream* inputStream;
    std::ostream* outputStream;

private:
    std::unique_ptr<std::istream> ownedInput;
    std::unique_ptr<std::ostream> ownedOutput;
};

#endif //OOP1PROJEKAT_BASECOMMAND_H
