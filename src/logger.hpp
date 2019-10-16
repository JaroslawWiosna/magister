#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void makeLogEntry(std::string text);  
private:
    static std::string loggerFilepath;
};

#endif // LOGGER_H