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
    using FunWraper = std::function<BaseCommand*(ParsedCommand)>;
    BaseCommand(ParsedCommand parsed,
                std::unique_ptr<std::istream> ownedInput,
                std::unique_ptr<std::ostream> ownedOutput);

    virtual ~BaseCommand() = default;
    virtual void execute() = 0;

    void setInputStream(std::istream* in) { inputStream = in; }
    void setOutputStream(std::ostream* out) { outputStream = out; }

    virtual bool hasInput() const { return true; }
    virtual bool hasOutput() const { return true; }

protected:
    ParsedCommand parsed;
    std::istream* inputStream;
    std::ostream* outputStream;


private:
    std::unique_ptr<std::istream> ownedInput;
    std::unique_ptr<std::ostream> ownedOutput;
};

#endif //OOP1PROJEKAT_BASECOMMAND_H
