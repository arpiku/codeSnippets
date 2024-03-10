
std::vector<std::string> splitIntoWords(const std::string& str) {
    std::vector<std::string> words;
    std::istringstream stream(str);
    std::string word;
    
    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}
