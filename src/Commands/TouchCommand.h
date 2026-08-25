//
// Created by vladi on 8/25/2026.
//

#ifndef OOP1PROJEKAT_TOUCHCOMMAND_H
#define OOP1PROJEKAT_TOUCHCOMMAND_H
#include "../Command/BaseCommand.h"
#include "../IOResolver/OutputResolver.h"

class TouchCommand :public BaseCommand {
  public:
  using BaseCommand::BaseCommand;
  void execute() override;
    static BaseCommand* create(ParsedCommand parsed) {
        auto output = OutputResolver::resolve(parsed);
        return new TouchCommand(std::move(parsed), nullptr, std::move(output));
    }
};
#endif //OOP1PROJEKAT_TOUCHCOMMAND_H