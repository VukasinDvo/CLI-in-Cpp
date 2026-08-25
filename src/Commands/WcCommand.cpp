//
// Created by vladi on 8/25/2026.
//
#include "WcCommand.h"
#include "../Exeptions/CommandExeptions.h"

void WcCommand::execute() {
    if (parsed.option == "w") {
        *outputStream << CountWords() << "\n";
    } else if (parsed.option == "c") {
        *outputStream << CountCharacters() << "\n";
    } else {
        throw CommandExecutionException("wc: obavezna je opcija -w ili -c");
    }
}

int WcCommand::CountCharacters() {
    int count =0;
    char c;
    while (inputStream->get(c)) {
        count++;
    }
    return count;
}

int WcCommand::CountWords() {
    int count =0;
    bool insideWord = false;
    char c;
    while (inputStream->get(c)) {
        if (std::isspace((unsigned char)c)) {
            insideWord = false;
        } else if (!insideWord) {
            insideWord = true;
            count++;
        }
    }

    return count;
}

