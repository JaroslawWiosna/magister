#ifndef COMPILETIMESENTENCES_DEMO_H
#define COMPILETIMESENTENCES_DEMO_H

#include "CacheOfSentences.hpp"

const std::vector<std::pair<std::string, std::string>> compileTimeSentences_vec {
    {{"veni vidi vici"}, {"I came, I saw, I conquered"}},
    {{"ante bellum"}, {"before the war"}},
    {{"mea culpa"}, {"my fault"}},
    {{"non ducor, duco"}, {"I am not led, I lead"}},
    {{"semper fidelis"}, {"always faithful"}},
    {{"semper paratus"}, {"always prepared"}},    
    {{"vox populi"}, {"voice of the people"}},
    {{"para bellum"}, {"prepare for war"}},
    {{"bona fide"}, {"in good faith"}},
    {{"mala fide"}, {"in bad faith"}},
    
 };

const CacheOfSentences compileTimeSentences{compileTimeSentences_vec};

#endif // COMPILETIMESENTENCES_DEMO_H

