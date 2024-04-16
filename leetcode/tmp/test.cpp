#include<iostream>

void findLongestPalindrome(std::string& s) {
  auto start = s.begin();
  auto end = s.end();

  auto expandPalindrome = [&](auto left, auto right) {
    while(left >= start && right < end && *left == *right ) {
      --left;
      ++right;
    }
    return std::make_tuple(left+1,right);
  }
}
