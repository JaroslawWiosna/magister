#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void makeLogEntry(const std::string& text);
private:
    static std::string loggerFilepath;
};

#endif // LOGGER_H