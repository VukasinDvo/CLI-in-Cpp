//
// Created by vladi on 9/7/2026.
//

#include "HeadCommand.h"
#include "../Exeptions/CommandExeptions.h"
#include <string>

int HeadCommand::parseLineCount() {
    const std::string& opt = parsed.option;

    if (opt.size() < 2 || opt[0] != 'n') {
        throw CommandExecutionException("head: opcija mora biti oblika -nCOUNT");
    }

    std::string digits = opt.substr(1);

    if (digits.empty() || digits.size() > 5) {
        throw CommandExecutionException("head: broj linija mora imati 1-5 cifara");
    }

    for (char c : digits) {
        if (!std::isdigit((unsigned char)c)) {
            throw CommandExecutionException("head: -n mora biti praceno samo ciframa");
        }
    }

    return std::stoi(digits);
}

void HeadCommand::execute() {
    if (parsed.option.empty()) {
        throw CommandExecutionException("head: obavezna je opcija -n");
    }

    int lineCount = parseLineCount();
    std::string line;
    int linesWritten = 0;

    while (linesWritten < lineCount && std::getline(*inputStream, line)) {
        *outputStream << line << "\n";
        linesWritten++;
    }
}