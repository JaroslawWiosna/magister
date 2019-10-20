#include "Lesson.hpp"
#include "CacheOfSentences.hpp"

Lesson::Lesson(const CacheOfSentences& cache) : totalCnt{3}, sentences{cache} {

}

void Lesson::start() {
    std::cout << "We have " << totalCnt << " sentences to translate:" << "\n";

    unsigned int i{};
    for (auto it=sentences.cache.begin(); i < totalCnt; i++, it++) {
        std::cout << (i+1) << ".\t" << (**it).english << "\n";
        auto suggestedAnswers = suggestAnswers(*it, sentences.cache);

        unsigned int j{};
        for (const auto& item : suggestedAnswers.answers) {
            std::cout << j++ << ". " << item << ", ";
        }
        std::cout << "\n";

        unsigned int userAnswer;
        std::cin >> userAnswer;

        std::cout << "Your answer is " << userAnswer << "\n";
        if (suggestedAnswers.idCorrectAnswer == userAnswer) {
            correctAnswersCnt++;
        }
    }

}

void Lesson::summary() {
    std::cout << "Summary of the lesson:" << "\n";
    std::cout << "Your score is: " << correctAnswersCnt << "/" << totalCnt << "\n";
}

SuggestedAnswers Lesson::suggestAnswers(std::shared_ptr<Sentence> current, const std::list<std::shared_ptr<Sentence>>& sentences) {
    SuggestedAnswers result;
    result.answers.push_back(current->latin);
    result.idCorrectAnswer = 0;

    auto it = sentences.begin();
    while (result.answers.size() < 3) {
        if (*it == current) {
            it++;
            continue;
        }
        result.answers.push_back((**it).latin);
        it++;
    }

    return result;
}

Lesson Lesson::makeLesson(const CacheOfSentences& cache) {
    return Lesson{cache};
}