#include "logger.hpp"
#include "PoFileEntry.hpp"
#include <iostream>

int main() {
    std::puts ("Hello magister!");
    std::cout << __cplusplus << "\n";
    Logger::makeLogEntry("Hello magister :)");

    auto lst = po::readPoFile("../dict.txt");

    po::prettyPrint(lst);

    return 0;
}
