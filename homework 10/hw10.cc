#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>      
#include "pattern.h"    

int main() {
    
    // training text input vars
    std::string filename = "training_data.txt";
    std::ifstream in(filename);
    std::string word;
    std::string training_text;
    
    // pattern training vars
    int length = 4;
    std::unordered_map<std::string, int> patterns;
    
    // lookup table
    std::unordered_map<std::string, std::vector<Pattern>> lookup_table;
    
    // concatenate txt file to a string
    while (in >> word) { // while in not blank
    
        training_text += word + " "; // concatenate with spaces
    
    }
    
    // find counts of patterns
    for (size_t i = 0; i+length<=training_text.size(); ++i) {
    
        std::string pattern = training_text.substr(i, length);
        patterns[pattern] += 1; // every time a sub string of length is found, add to the pattern count
    
    }
    
    // prefix (length-1 chars) >> vector of possible patterns
    
    // fills lookup table
    for (auto &pattern : patterns) {
    
        const std::string &curr = pattern.first;
        int &count = pattern.second;
    
        std::string prefix = curr.substr(0, length-1);
    
        lookup_table[prefix].push_back(Pattern(curr, count));
    
    }
    
    // calc probabilities
    for (auto &look : lookup_table) {
    
        auto &pattern = look.second;
    
        int total_sum = 0;
        for (auto &patt : pattern) total_sum += patt.count;
    
        int running_sum = 0;
        for (auto &patt : pattern) {
    
            running_sum += patt.count;
            patt.probability = (double) running_sum / (double) total_sum;
    
        }
    
    }
    
    // generate text
    std::string text = "The";
    
    while (text.size() < 2000) {
    
        std::string prefix = text.substr(text.size() - (length - 1));
    
        auto &pattern = lookup_table[prefix];
    
        double r = (double)rand() / (double)RAND_MAX;
    
        for (auto &patt : pattern) {
    
            if (patt.probability >= r) {
    
                char next_char = patt.full.back();
                text += next_char;
                break;
    
            }
    
        }
    
    }
    
    std::cout << "Generated text:\n";
    std::cout << text << std::endl;
}