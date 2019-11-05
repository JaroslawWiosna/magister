#include "Sentence.hpp"
#include <algorithm>
#include <array>
#include <functional>
#include <sstream>
#include <vector>
#include <iostream>

bool equalLength(const std::string& first, const std::string& second) {
    return (first.size() == second.size());
}

bool equalWordCnt(const std::string& first, const std::string& second) {
    return (std::count(first.begin(), first.end(), ' ') + 1 
         == std::count(second.begin(), second.end(), ' ') + 1);
}

template <int n>
bool nWordsAreTheSame(const std::string& first, const std::string& second) {
    using namespace std;
    int cnt{};
    vector<string> firstAsWords, secondAsWords;
    {
        istringstream ss{first};
        do {
            string word;
            ss >> word;
            firstAsWords.push_back(word);
        } while(ss);
    }
    {
        istringstream ss{second};
        do {
            string word;
            ss >> word;
            secondAsWords.push_back(word);
        } while(ss);
    }

    for (auto w1 : firstAsWords) {
        for (auto w2 : secondAsWords) {
            if (w1 == w2) {
                ++cnt;
            }
        }
    }
    
    return cnt >= n;
}

template<int n>
void addFun(std::vector<std::function<bool(const std::string&, const std::string&)>> &functions)
{
    addFun<n - 1>(functions);
    functions.push_back(nWordsAreTheSame<n - 1>);
}

template<>
void addFun<0>(std::vector<std::function<bool(const std::string&, const std::string&)>> &functions)
{
}

SimilarityMeasure makeMeasure(const std::string& first, const std::string& second) {
    float trueCnt{};
    constexpr int arraySize{4};
    // TODO: Consider using vector instead of array
    // Because it will be easier to maintain, i.e. when adding new function to functions
    std::vector<std::function<bool(const std::string&, const std::string&)>> functions = {
        equalLength,
        equalWordCnt
    };

    addFun<3>(functions);
    std::cout << functions.size() << "\n";
 
    for (auto f : functions) {
        if (f(first, second)) {
            ++trueCnt;
        }
    }
    
    return trueCnt / arraySize;
}
