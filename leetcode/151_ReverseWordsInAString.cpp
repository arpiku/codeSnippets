class Solution {
public:
    std::vector<std::string> splitStringBySpaces(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> words;
    std::string word;

    while (stream >> word) {
        words.push_back(word);
    }

    return words;
    }

    std::string joinWordsWithSpaces(const std::vector<std::string>& words) {
    if (words.empty()) return "";

    return std::accumulate(std::next(words.begin()), words.end(), words[0],
                           [](const std::string& a, const std::string& b) {
                               return a + " " + b;
                           });
}


    string reverseWords(string s) {
        std::vector<std::string> words = splitStringBySpaces(s);
        std::reverse(words.begin(),words.end());
        return joinWordsWithSpaces(words);
        
    }
};
