//
// Created by vladi on 8/25/2026.
//
#include "PromptCommand.h"
#include "../Exeptions/CommandExeptions.h"
std::string PromptCommand::prompt="$";

void PromptCommand::execute() {
    if (!parsed.argument.has_value()||!parsed.isQuoted) {
        throw CommandExecutionException("prompt zahteva argumet pod navodnicima");

    }
    prompt= *parsed.argument;

}
std::string PromptCommand::getPrompt() {
    return PromptCommand::prompt;
}