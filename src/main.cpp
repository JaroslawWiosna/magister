#include "logger.hpp"
#include "Lesson.hpp"
#include "PoFileEntry.hpp"
#include "CacheOfSentences.hpp"
#include "CompileTimeSentences_demo.hpp"
#include <iostream>

int main() {
    std::puts ("Hello magister!");
    std::cout << __cplusplus << "\n";
    Logger::makeLogEntry("Hello magister :) ;)");

    auto lst = po::readPoFile("../dict.txt");

    // po::prettyPrint(lst);

    CacheOfSentences cache{lst};

    auto lesson = Lesson::makeLesson(getCompileTimeSentences());

    lesson.start();
    lesson.summary();

    return 0;
}
