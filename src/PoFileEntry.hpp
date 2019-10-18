#include <iostream>
#include <string>
#include <list>

namespace po {

struct PoFileEntry {
    PoFileEntry(std::string msgid, std::string msgstr) : msgid{msgid}, msgstr{msgstr} {}
    std::string msgid;
    std::string msgstr;
};

std::list<PoFileEntry> readPoFile(std::string filepath);

void prettyPrint(const std::list<PoFileEntry>& lst);

}