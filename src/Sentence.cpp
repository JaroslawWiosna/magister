#include "Sentence.hpp"

SimilarityMeasure makeMeasure(const std::string& first, const std::string& second) {
    if (first == second) {
        return 1.0f;
    } else {
        return 0.0f;
    }
}
