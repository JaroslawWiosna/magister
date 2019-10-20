#ifndef LESSON_H
#define LESSON_H

#include "CacheOfSentences.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct SuggestedAnswers {
    unsigned int idCorrectAnswer;
    std::vector<std::string> answers;
};

class Lesson {
public:
explicit Lesson(const CacheOfSentences&);
static Lesson makeLesson(const CacheOfSentences& cache);
void start();
void summary();
SuggestedAnswers suggestAnswers(std::shared_ptr<Sentence>, const std::list<std::shared_ptr<Sentence>>& sentences);

private:
    unsigned int totalCnt;
    unsigned int correctAnswersCnt{};
    CacheOfSentences sentences;
};

#endif // LESSON_H