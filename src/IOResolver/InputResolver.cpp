//
// Created by vladi on 8/22/2026.
//
#include "InputResolver.h"
#include <sstream>
#include <fstream>
#include "../Exeptions/CommandExeptions.h"

std::unique_ptr<std::istream> InputResolver::resolve(const ParsedCommand& cmd) {
    if (!cmd.argument.has_value()) {
        return nullptr;
    }

    if (cmd.isQuoted) {
        return std::make_unique<std::istringstream>(*cmd.argument);
    }

    auto file = std::make_unique<std::ifstream>(*cmd.argument);
    if (!file->is_open()) {
        throw CommandExecutionException("Ne mogu da otvorim fajl: " + *cmd.argument);
    }
    return file;
}