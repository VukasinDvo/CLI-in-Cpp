#include <iostream>
#include "src/LineParser/ParsedCommand.h"
#include "src/IOResolver/OutputResolver.h"
#include "src/Command/BaseCommand.h"
#include "src/CommandFactory/CommandFactory.h"
#include "src/LineParser/Parser.h"

void runTest(Parser& parser, const std::string& line) {
    std::cout << "--- " << line << " ---\n";
    try {
        BaseCommand* cmd = parser.parseCmd(line);
        cmd->execute();
        delete cmd;
    } catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << "\n";
    }
    std::cout << "\n";
}

int main() {
    CommandFactory factory;
    Parser parser(factory);

    // Test 1: echo sa citiranim argumentom
    runTest(parser, "echo \"Zdravo svete\"");

    // Test 2: time
    runTest(parser, "time");

    // Test 3: date
    runTest(parser, "date");

    // Test 4: touch - pravi novi fajl
    runTest(parser, "touch test_touch.txt");

    // Test 5: touch na fajlu koji vec postoji - ocekivana greska
    runTest(parser, "touch test_touch.txt");

    // Test 6: wc -w sa citiranim argumentom
    runTest(parser, "wc -w \"Lorem ipsum dolor sit amet, consectetur adipiscing elit\"");

    // Test 7: wc -c sa citiranim argumentom
    runTest(parser, "wc -c \"Lorem ipsum\"");

    // Test 8: wc bez opcije - ocekivana semanticka greska
    runTest(parser, "wc \"Lorem ipsum\"");

    // Test 9: nepoznata komanda - ocekivana greska
    runTest(parser, "nepostojeca komanda");

    return 0;
}