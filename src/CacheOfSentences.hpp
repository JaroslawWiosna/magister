#ifndef CACHEOFSENTENCES_H
#define CACHEOFSENTENCES_H

#include "PoFileEntry.hpp"
#include "Sentence.hpp"

#include <iostream>
#include <memory>
#include <list>

class CacheOfSentences {
public:
    CacheOfSentences(const std::list<po::PoFileEntry>& lst) {
    unsigned int id{};
        for (const auto &[msgid, msgstr] : lst) {
            cache.push_back(std::make_shared<Sentence>(id++, msgid, msgstr));
        }

        for (auto& i : cache) {
            for (const auto& j : cache) {
                i->others[j] = makeMeasure(i->latin, j->latin);
            }
        }
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            for (auto jt = cache.begin(); jt != cache.end(); ++jt) {
                std::cout << (**it).english << "\t" << (**jt).latin << "\tSimilar? " << (**it).others[*jt] << "\n";
                
            }
        }

    }

private:
    std::list<std::shared_ptr<Sentence>> cache;

};

#endif // CACHEOFSENTENCES_H
