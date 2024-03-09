class Solution {
public:
    bool isAnagram(string s, string t) {
        auto stringHasher = [](string s) {
            std::unordered_map<char,int> m;
            for(auto& ch:s) {
                m[ch]++;
            }
            return m;
        };
        return stringHasher(s) == stringHasher(t);
    }
};
