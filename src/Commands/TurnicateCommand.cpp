//
// Created by vladi on 8/26/2026.
//

#include "TurnicateCommand.h"

#include <filesystem>
#include <fstream>

#include "../Exeptions/CommandExeptions.h"
void TurnicateCommand::execute() {
    if (!parsed.argument.has_value()) {
        throw CommandExecutionException("Turnicate mora imati naziv fajla");
    }
    if (!std::filesystem::exists(*parsed.argument)) {
        throw CommandExecutionException("Fajl sa imenom " + *parsed.argument + " ne postoji");
    }
    std::ofstream file(*parsed.argument, std::ios::trunc);
    if (!file.is_open()) {
        throw CommandExecutionException("Ne mogu da otvorim fajl: " + *parsed.argument);
    }
}
