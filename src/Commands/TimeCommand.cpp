//
// Created by vladi on 8/25/2026.
//
#include "TimeCommand.h"

#include <ctime>
#include <iomanip>

void TimeCommand::execute() noexcept{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    *outputStream << std::put_time(localTime, "%H:%M:%S") << "\n";
}
