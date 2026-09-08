//
// Created by vladi on 8/22/2026.
//

#include "OutputResolver.h"
#include <fstream>
#include "../Exeptions/CommandExeptions.h"

std::unique_ptr<std::ostream> OutputResolver::resolve(const ParsedCommand &cmd) {
    if (!cmd.outputRedirectFile.has_value()) {
        return nullptr;
    }
    std::unique_ptr<std::ofstream> file;


    if (cmd.appendOutput) {
        file = std::make_unique<std::ofstream>(*cmd.outputRedirectFile, std::ios::app);
    } else {
        file = std::make_unique<std::ofstream>(*cmd.outputRedirectFile, std::ios::trunc);
    }

    return file;
}