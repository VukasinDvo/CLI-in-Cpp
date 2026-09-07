//
// Created by vladi on 9/6/2026.
//

#include "TrCommand.h"
#include "../Exeptions/CommandExeptions.h"
#include <sstream>

void TrCommand::execute() {
    if (parsed.option.empty()) {
        throw CommandExecutionException("Tr zahteva -what argument");
    }
    const std::string& what = parsed.option;
    const std::string with = parsed.extraArguments.empty() ? "": parsed.extraArguments[0];

    std::ostringstream buffer;
    buffer << inputStream->rdbuf();
    std::string text= buffer.str();

    size_t pos=0;
    while ((pos=text.find(what,pos)) != std::string::npos) {
        text.replace(pos,what.length(),with);
        pos+=with.length();
    }

    *outputStream << text;


}