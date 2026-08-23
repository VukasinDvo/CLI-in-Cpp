//
// Created by vladi on 8/22/2026.
//

#ifndef OOP1PROJEKAT_OUTPUTRESOLVER_H
#define OOP1PROJEKAT_OUTPUTRESOLVER_H
#include <iostream>
#include <memory>

#include "../LineParser/ParsedCommand.h"


class OutputResolver {
    public:
    static std::unique_ptr<std::ostream> resolve(const ParsedCommand &cmd);
};
#endif //OOP1PROJEKAT_OUTPUTRESOLVER_H