//Review the mistakes 
//
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
        if (pattern.size() != words.size()) {
            return false;
        }

        std::unordered_map<char, std::string> charToWord;
        std::unordered_set<std::string> usedWords;
        
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const std::string& w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                if (!usedWords.insert(w).second) {
                    // Failed to insert means word is already used for another char
                    return false;
                }
                charToWord[c] = w;
            }
        }

        return true;
    }
};

//Above is correct solution, below is not 
//
//
bool wordPattern(string pattern, string s) {
        auto words = splitIntoWords(s);
        if(pattern.size() != words.size())
            return false;

        std::unordered_map<char,std::string> charToWord;
        std::unordered_set<std::string> usedWords;
        auto charItr = pattern.begin();
        auto wordItr = words.begin();

        while(charItr != pattern.end() && wordItr != words.end()) {
            if(charToWord.count(*charItr) && charToWord[*charItr] != *wordItr)
                return false;
            else {
                if (!usedWords.insert(*wordItr).second) {
                return false;
            }
            charToWord[*charItr] = *wordItr;
            }
        }



        return true;
    }
