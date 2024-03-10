
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> splitIntoWords(const std::string& str) {
        std::vector<std::string> words;
        std::istringstream stream(str);
        std::string word;
        
        while (stream >> word) {
            words.push_back(word);
        }

        return words;
    }
  
    bool wordPattern(std::string pattern, std::string s) {
        auto words = splitIntoWords(s);
        if(pattern.size() != words.size()) {
            return false;
        }

        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;
        
        for(int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const std::string& w = words[i];

            if(charToWord.count(c) && charToWord[c] != w) {
                return false; // Mismatch in mapping from char to word
            }
            if(wordToChar.count(w) && wordToChar[w] != c) {
                return false; // Mismatch in mapping from word to char
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};
