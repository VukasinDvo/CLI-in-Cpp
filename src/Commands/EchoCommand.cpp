//
// Created by vladi on 8/22/2026.
//
#include "EchoCommand.h"
void EchoCommand::execute() {
    char c;
    while (inputStream->get(c)) {
        outputStream->put(c);
    }
}
