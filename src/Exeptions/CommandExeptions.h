//
// Created by vladi on 8/22/2026.
//

#ifndef OOP1PROJEKAT_COMMANDEXEPTIONS_H
#define OOP1PROJEKAT_COMMANDEXEPTIONS_H
#include <stdexcept>


class CommandExeptions {
};
class UnknownCommandException : public std::runtime_error {
public:
    explicit UnknownCommandException(const std::string& name)
        : std::runtime_error("Unknown command: " + name) {}
};
class CommandExecutionException : public std::runtime_error {
public:
    explicit CommandExecutionException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif //OOP1PROJEKAT_COMMANDEXEPTIONS_H