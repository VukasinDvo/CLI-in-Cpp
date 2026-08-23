//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_PIPELINECOMMAND_H
#define OOP1PROJEKAT_PIPELINECOMMAND_H
#include "BaseCommand.h"


class PipelineCommand:public BaseCommand {

public:
    explicit PipelineCommand(std::vector<BaseCommand*> commands);
    ~PipelineCommand() override;
    void execute() override;


private:
    std::vector<BaseCommand*> commands;

};
#endif //OOP1PROJEKAT_PIPELINECOMMAND_H
