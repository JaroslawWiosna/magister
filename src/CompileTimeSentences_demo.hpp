#ifndef COMPILETIMESENTENCES_DEMO_H
#define COMPILETIMESENTENCES_DEMO_H

#include "CacheOfSentences.hpp"

const std::vector<std::pair<std::string, std::string>> compileTimeSentences_vec {
    {{"to the archives"}, {"ad acta"}},
    {{"water"}, {"aqua"}},
    {{"to dare is to do"}, {"audere est facere"}},
};

const CacheOfSentences compileTimeSentences{compileTimeSentences_vec};

#endif // COMPILETIMESENTENCES_DEMO_H

