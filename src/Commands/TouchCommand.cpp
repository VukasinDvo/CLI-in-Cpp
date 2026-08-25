//
// Created by vladi on 8/25/2026.
//

#include "TouchCommand.h"

#include <filesystem>
#include <fstream>

#include "../Exeptions/CommandExeptions.h"

void TouchCommand::execute() {
    if (std::filesystem::exists(*parsed.argument)) {
        throw CommandExecutionException("Fajl vec postoji");
    }
    std::ofstream file(*parsed.argument);

}

