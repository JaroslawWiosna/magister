#include "Lesson.hpp"
#include "CacheOfSentences.hpp"

#include <algorithm>
#include <random>

unsigned int generateRandomNumber(unsigned int a, unsigned int b) {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

    return dist(rng);
}

unsigned int generateRandomNumberFromOneTo(unsigned int n) {
    return generateRandomNumber(1, n);
}

unsigned int generateRandomNumberFromZeroTo(unsigned int n) {
    return generateRandomNumber(0, n);
}

std::vector<unsigned int> generate_x_unique_number_from_1_to_n(unsigned int x, unsigned int n) {
    if (x > n) {
        throw;
    }

    std::vector<unsigned int> result;
    result.reserve(x);
    while (result.size() < x) {
        auto tmp = generateRandomNumberFromOneTo(n);
        if (result.end() != std::find(result.begin(), result.end(), tmp)) {
            continue;
        } else {
            result.push_back(tmp);
        }
    }
    return result;
}


Lesson::Lesson(const CacheOfSentences& cache) : totalCnt{3}, sentences{cache} {

}

void Lesson::start() {
    std::cout << "We have " << totalCnt << " sentences to translate:" << "\n";

    unsigned int i{};
    for (auto it=sentences.cache.begin(); i < totalCnt; i++, it++) {
        std::cout << (i+1) << ". " << (**it).english << "\n";
        auto suggestedAnswers = suggestAnswers(*it, sentences.cache);

        unsigned int j{};
        for (const auto& item : suggestedAnswers.sentences) {
            std::cout << "\t" << j++ << ". " << (*item).latin << "\n";
        }
        std::cout << "\n";

        unsigned int userAnswer;
        std::cin >> userAnswer;

        if (suggestedAnswers.idCorrectAnswer == userAnswer) {
            correctAnswersCnt++;
            // To do: shuffle between "Great, outstanding, Magnificent"
            std::cout << "Very well!" << "\n";
        } else {
            std::cout << ":'-(" << "\n";
        }
    }

}

void Lesson::summary() {
    std::cout << "Summary of the lesson:" << "\n";
    std::cout << "Your score is: " << correctAnswersCnt << "/" << totalCnt << "\n";
}

// TODO(#18): The correct answer is always first
// Let's shuffle suggested answers!
SuggestedAnswers Lesson::suggestAnswers(std::shared_ptr<Sentence> current, const std::list<std::shared_ptr<Sentence>>& sentences) {
    // we take current by copy, so... ref_cnt is incremented, right?
    SuggestedAnswers result;
    //push_back weak_ptr
    result.sentences.push_back(current);

    auto it = sentences.begin();
    while (result.sentences.size() < 3) {
        it = sentences.begin();
        std::advance(it, generateRandomNumberFromZeroTo(sentences.size() - 1));
        if (*it == current) {
            continue;
        }
        if (result.sentences.end() != std::find(result.sentences.begin(), result.sentences.end(), *it)) {
            continue;
        } 
        result.sentences.push_back(*it);
    }

    result.idCorrectAnswer = 0;
    return result;
}

Lesson Lesson::makeLesson(const CacheOfSentences& cache) {
    return Lesson{cache};
}
