//
// Created by vladi on 8/22/2026.
//

#include "CommandFactory.h"
#include "../IOResolver/InputResolver.h"
#include "../IOResolver/OutputResolver.h"

#include "../Commands/CommandHeader.h"
#include "../Exeptions/CommandExeptions.h"

CommandFactory::CommandFactory() {
    commands["echo"]=&EchoCommand::create;
    commands["time"]=&TimeCommand::create;
    commands["date"]=&DateCommand::create;
    commands["touch"]=&TouchCommand::create;
    commands["wc"]=&WcCommand::create;
    commands["prompt"]=&PromptCommand::create;
    commands["turnicate"]=&TurnicateCommand::create;
    commands["rm"]=&RmCommand::create;
};
BaseCommand* CommandFactory::create(const ParsedCommand& parsed) const {
    auto it = commands.find(parsed.name);
    if (it == commands.end()) {
        throw UnknownCommandException(parsed.name);
    }
    return it->second(parsed);
};