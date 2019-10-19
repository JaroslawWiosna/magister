#include "logger.hpp"
#include <iostream>
#include <fstream>

std::string Logger::loggerFilepath = "./log_magister.txt";

void Logger::makeLogEntry(const std::string& text) {
    using namespace std;
    ofstream file;
    file.open(loggerFilepath);
    file << text << "\n";
    file.close();
}