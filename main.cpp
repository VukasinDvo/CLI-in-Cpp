#include <iostream>
#include "src/LineParser/ParsedCommand.h"
#include "src/IOResolver/OutputResolver.h"

#include "src/Command/BaseCommand.h"
#include "src/CommandFactory/CommandFactory.h"


int main() {
    CommandFactory* factory=new CommandFactory();

    // Test 1: echo bez argumenta (trebalo bi da cita sa std::cin)
    // preskacemo ovaj test za sad, testirajmo prvo laksi slucaj

    // Test 2: echo sa citiranim argumentom
    ParsedCommand parsed;
    parsed.name = "echo";
    parsed.argument = "Zdravo svete";
    parsed.isQuoted = true;

    try {
        BaseCommand* cmd = factory->create(parsed);
        cmd->execute();   // ocekivano: ispisuje "Zdravo svete"
        delete cmd;
    } catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << "\n";
    }

    return 0;
}
