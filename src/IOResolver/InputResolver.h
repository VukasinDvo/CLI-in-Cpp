//
// Created by vladi on 8/22/2026.
//

#ifndef OOP1PROJEKAT_INPUTRESOLVER_H
#define OOP1PROJEKAT_INPUTRESOLVER_H
#include <iostream>
#include <memory>

#include "../LineParser/ParsedCommand.h"


class InputResolver {
    public:
    static std::unique_ptr<std::istream> resolve(const ParsedCommand& cmd);
};
#endif //OOP1PROJEKAT_INPUTRESOLVER_H