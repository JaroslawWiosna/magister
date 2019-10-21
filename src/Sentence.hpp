#ifndef SENTENCE_H
#define SENTENCE_H

#include <string>
#include <map>
#include <memory>

using SimilarityMeasure = float;

struct Sentence {
    Sentence(const std::string& english, const std::string& latin) : id{0}, english{english}, latin{latin}, others{} {}
    Sentence(unsigned int id, const std::string& english, const std::string& latin) : id{id}, english{english}, latin{latin}, others{} {}

    unsigned int id;
    std::string english;
    std::string latin;
    // https://forum.wordreference.com/threads/similarity-vs-resemblance.2634312/
    std::map<std::shared_ptr<Sentence>, SimilarityMeasure> others;
};

SimilarityMeasure makeMeasure(const std::string& first, const std::string& second);

#endif // SENTENCE_H