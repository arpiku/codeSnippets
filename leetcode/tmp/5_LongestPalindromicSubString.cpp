#include"utils.h"

void findLongestPalindrome(const std::string& str) {
    auto start = str.begin();
    auto end = str.end();

    auto expandPalindrome = [&](auto left, auto right) {
        while (left >= str.begin() && right < str.end() && *left == *right) {
            --left;
            ++right;
        }
        return std::make_tuple(left + 1, right);
    };

    auto longest = std::make_tuple(start, start);

    for (auto it = str.begin(); it != str.end(); ++it) {
        auto [left1, right1] = expandPalindrome(it, it);
        auto [left2, right2] = expandPalindrome(it, it + 1);

        if (right1 - left1 > std::get<1>(longest) - std::get<0>(longest)) {
            longest = std::make_tuple(left1, right1);
        }

        if (right2 - left2 > std::get<1>(longest) - std::get<0>(longest)) {
            longest = std::make_tuple(left2, right2);
        }
    }

    auto [leftx,rightx] = longest;

    std::string out = std::string(leftx,rightx);
    std::cout << out << std::endl;
}

int main() {
    std::string str = "aaaa";
    findLongestPalindrome(str);
    

    return 0;
}

