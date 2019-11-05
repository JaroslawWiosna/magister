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

std::vector<unsigned int> generate_x_unique_number_from_0_to_n(unsigned int x, unsigned int n) {
    if (x > n) {
        throw;
    }

    std::vector<unsigned int> result;
    result.reserve(x);
    while (result.size() < x) {
        auto tmp = generateRandomNumberFromZeroTo(n);
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

    std::cout << "\n------------\n";

    unsigned int i{};
    auto rndIndexes = generate_x_unique_number_from_0_to_n(totalCnt, sentences.cache.size()-1);
    for (const auto& index : rndIndexes) {
    // for (auto it=sentences.cache.begin(); i < totalCnt; i++, it++) {
        auto it = sentences.cache.begin();
        std::advance(it, index);
        std::cout << "\n\t" << (**it).english << "\n\n";
        auto suggestedAnswers = suggestAnswers(*it, sentences.cache);

        unsigned int j{1};
        for (const auto& item : suggestedAnswers.sentences) {
            std::cout << j++ << ". " << (*item).latin << "\n";
        }
        std::cout << "\n";

        unsigned int userAnswer;
        std::cin >> userAnswer;

        if (suggestedAnswers.idCorrectAnswer == (userAnswer-1)) {
            correctAnswersCnt++;
            // To do: shuffle between "Great, outstanding, Magnificent"
            std::cout << "Very well!" << "\n";
        } else {
            std::cout << ":'-(" << "\n";
        }
        ++i;
        std::cout << "\n------------\n";

    }

}

void Lesson::summary() {
    std::cout << "Summary of the lesson:" << "\n";
    std::cout << "Your score is: " << correctAnswersCnt << "/" << totalCnt << "\n";
}

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
        if (makeMeasure((*it)->latin, current->latin) < SimilarityMeasure{0.6f}) {
            continue;
        }
        result.sentences.push_back(*it);
    }

    // The correct answer is always first, so swap option A with B or C randomly
    result.idCorrectAnswer = generateRandomNumberFromZeroTo(2);
    auto begin = result.sentences.begin();
    auto jt = result.sentences.begin();
    std::advance(jt, result.idCorrectAnswer);
    std::swap(*begin, *jt);

    return result;
}

Lesson Lesson::makeLesson(const CacheOfSentences& cache) {
    return Lesson{cache};
}
