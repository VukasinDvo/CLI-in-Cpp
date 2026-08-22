//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_PROMPTCOMMAND_H
#define OOP1PROJEKAT_PROMPTCOMMAND_H

class PromptCommand : public BaseCommand {
    public:
    PromptCommand(std::vector<std::string> args);
    void execute() override;
};
#endif //OOP1PROJEKAT_PROMPTCOMMAND_H