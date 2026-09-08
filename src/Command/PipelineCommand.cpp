//
// Created by vladi on 8/21/2026.
//

#include "PipelineCommand.h"
#include "BaseCommand.h"
#include <vector>


PipelineCommand::PipelineCommand(std::vector<BaseCommand*> commands)
    : BaseCommand(ParsedCommand{}, nullptr, nullptr), commands(std::move(commands)) {}

PipelineCommand::~PipelineCommand() {
    for (auto* cmd : commands) {
        delete cmd;
    }
}

void PipelineCommand::execute() {
    std::vector<std::unique_ptr<std::stringstream>> buffer;

}

void PipelineCommand::validateCommandPositions() {
    for (int i=0; i<commands.size(); i++) {
        bool isFirst= (i==0);
        bool isLast = (i == commands.size() - 1);
        if (!isFirst && !commands[i]->hasInput()) {
            throw PipelineExeptions(
                "Komanda bez ulaznog toka ne moze biti u sredini/na kraju pipeline-a");
        }
        if (!isLast && !commands[i]->hasOutput()) {
            throw PipelineExeptions(
                "Komanda bez izlaznog toka ne moze biti na pocetku/u sredini pipeline-a");
        }
    }
}
