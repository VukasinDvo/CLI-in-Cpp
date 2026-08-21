//
// Created by vladi on 8/21/2026.
//

#include "PipelineCommand.h"

PipelineCommand::PipelineCommand(std::vector<BaseCommand*> commands)
    : BaseCommand({}), commands(std::move(commands)) {}

PipelineCommand::~PipelineCommand() {
    for (auto* cmd : commands) {
        delete cmd;
    }
}

void PipelineCommand::execute() {
    // ovde ide fork()/pipe()/dup2() logika povezivanja komandi
    // (razradicemo kad dodjemo do izvrsavanja)
}