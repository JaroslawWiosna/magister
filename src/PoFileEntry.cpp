#include "PoFileEntry.hpp"
#include "logger.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

namespace po {

std::list<PoFileEntry> readPoFile(std::string filepath) {
    using namespace std;

    list<PoFileEntry> result;
    ifstream file(filepath.c_str());

    std::string line;
    while (getline(file, line)) {
        if (0 == line.find(string{"msgid \""})) {
            Logger::makeLogEntry("starter marker found");
            string english, latin;
            english = line.substr(7, line.size() - 8);
            getline(file, line);
            if (0 == line.find(string{"msgstr \""})) {
                latin = line.substr(8, line.size() - 9);
            }
            result.emplace_back(english,latin);       
        }
    }

    return result;
}

void prettyPrint(const std::list<PoFileEntry>& lst) {
    std::cout << "List:\n";
    for (const auto& [msgid, msgstr] : lst) {
        std::cout << msgid << "\n" << msgstr << "\n\n";
    }
}

}

