#ifndef CACHEOFSENTENCES_H
#define CACHEOFSENTENCES_H

#include "PoFileEntry.hpp"
#include "Sentence.hpp"

#include <iostream>
#include <memory>
#include <list>
#include <utility>
#include <vector>

class CacheOfSentences {
public:
    CacheOfSentences(const std::vector<std::pair<std::string, std::string>>& strs) {
        for (const auto& [key, value] : strs) {
            cache.push_back(std::make_shared<Sentence>(key, value));
        }
    }
    CacheOfSentences(const std::map<std::string, std::string>& dict) {
        for (const auto& [key, value] : dict) {
            cache.push_back(std::make_shared<Sentence>(key, value));
        }
    }
    explicit CacheOfSentences(const std::list<po::PoFileEntry>& lst) {
        for (const auto &[msgid, msgstr] : lst) {
            cache.push_back(std::make_shared<Sentence>(msgid, msgstr));
        }

        for (auto& i : cache) {
            for (const auto& j : cache) {
                i->others[j] = makeMeasure(i->latin, j->latin);
            }
        }
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            for (auto jt = cache.begin(); jt != cache.end(); ++jt) {
                // std::cout << (**it).english << "\t" << (**jt).latin << "\tSimilar? " << (**it).others[*jt] << "\n";
                
            }
        }

    }

// private:
    std::list<std::shared_ptr<Sentence>> cache;

};

#endif // CACHEOFSENTENCES_H
