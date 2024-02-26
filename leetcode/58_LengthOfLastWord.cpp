class Solution {
public:
    std::vector<std::string> splitAtSpaces(const std::string& string) {
        std::istringstream stream(string);
        std::vector<std::string> words;
        std::string word;
        while(stream >> word) {
            words.push_back(word);
        }
        return words;
    }
    int lengthOfLastWord(string s) {
        auto v = splitAtSpaces(s);
        std::string word = *v.rbegin();
        return word.size();

    }
};
