std::string minWindow(std::string s, std::string t) {
    if (s.empty() || t.empty()) {
        return "";
    }

    std::unordered_map<char, int> tFrequency, window;
    for (char c : t) {
        tFrequency[c]++;
    }

    int required = tFrequency.size();
    int formed = 0;
    int left = 0, right = 0;
    int minLen = std::numeric_limits<int>::max();
    int minLeft = 0;

    while (right < s.length()) {
        char c = s[right];
        window[c]++;

        if (tFrequency.find(c) != tFrequency.end() && window[c] == tFrequency[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }

            window[c]--;
            if (tFrequency.find(c) != tFrequency.end() && window[c] < tFrequency[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return minLen == std::numeric_limits<int>::max() ? "" : s.substr(minLeft, minLen);
}
