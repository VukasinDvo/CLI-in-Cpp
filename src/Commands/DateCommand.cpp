//
// Created by vladi on 8/25/2026.
//
#include "DateCommand.h"

#include <ctime>

#include "TimeCommand.h"
#include <iomanip>

void DateCommand::execute() noexcept {

        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        *outputStream << std::put_time(localTime, "%d.%m.%Y.") << "\n";
}
