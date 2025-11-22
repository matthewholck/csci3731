#ifndef PATTERN_H
#define PATTERN_H

#include <string>

class Pattern {
public:
    std::string full;     
    int count;            
    double probability;    

    Pattern(const std::string &f, int c);
};

#endif
