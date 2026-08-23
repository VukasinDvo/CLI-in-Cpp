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

}