//
// Created by vladi on 8/21/2026.
//

#include "BaseCommand.h"

BaseCommand::BaseCommand(ParsedCommand parsed,
                          std::unique_ptr<std::istream> ownedInput,
                          std::unique_ptr<std::ostream> ownedOutput)
    : parsed(std::move(parsed)),
      ownedInput(std::move(ownedInput)),
      ownedOutput(std::move(ownedOutput)) {

    inputStream  = this->ownedInput  ? this->ownedInput.get()  : &std::cin;
    outputStream = this->ownedOutput ? this->ownedOutput.get() : &std::cout;
}

