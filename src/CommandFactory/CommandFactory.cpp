//
// Created by vladi on 8/22/2026.
//

#include "CommandFactory.h"
#include "../IOResolver/InputResolver.h"
#include "../IOResolver/OutputResolver.h"

#include "../Commands/EchoCommand.h"
#include "../Exeptions/CommandExeptions.h"

CommandFactory::CommandFactory() {
    commands["echo"]=&EchoCommand::create;
}
BaseCommand* CommandFactory::create(const ParsedCommand& parsed) const {
    auto it = commands.find(parsed.name);
    if (it == commands.end()) {
        throw UnknownCommandException(parsed.name);
    }

    auto input = InputResolver::resolve(parsed);
    auto output = OutputResolver::resolve(parsed);

    return it->second(parsed, std::move(input), std::move(output));
}