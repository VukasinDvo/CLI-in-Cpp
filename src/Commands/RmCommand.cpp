//
// Created by vladi on 8/26/2026.
//

#include "RmCommand.h"
#include "../Exeptions/CommandExeptions.h"
#include <filesystem>

void RmCommand::execute() {
    if (!parsed.argument.has_value()) {
        throw CommandExecutionException("Komanda zahteva naziv fajla za brisanje");
    }
    if (!std::filesystem::exists(*parsed.argument)) {
        throw CommandExecutionException("Fajl ne postoji");
    }
    std::remove(parsed.argument->c_str());
}
