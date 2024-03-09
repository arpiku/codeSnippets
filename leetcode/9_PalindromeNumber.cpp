class Solution {
public:
    bool isPalindrome(const int x) {
        std::string o = std::to_string(x);
        std::string r = o;
        std::reverse(r.begin(),r.end());
        return r == o;
    }
};
