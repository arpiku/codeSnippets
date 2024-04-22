#include"utils.h"    
#include <cctype>
#include <limits>

template<typename T>
T atoi_impl(const char* str)
{
    while (std::isspace(static_cast<unsigned char>(*str)))
        ++str;
 
    bool negative = false;
 
    if (*str == '+')
        ++str;
    else if (*str == '-')
    {
        ++str;
        negative = true;
    }
 
    T result = 0;
    for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
    {
        int digit = *str - '0';
        result *= 10;
        result -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
    }
 
    return negative ? result : -result;
}

int myAtoi(std::string s) {
  bool negative = false;
  long result = 0;
  for (auto &ch : s) {
		if(std::isalpha(ch))
			return 0;
    if (std::isspace(ch) || ch == '+')
      continue;
    if (ch == '-') {
      negative = true;
    }
    if (std::isdigit(ch)) {
      int digit = ch - '0';
      result *= 10;
      result -= digit;
    }
  }
  auto max_int = std::numeric_limits<int>::max();
  auto min_int = std::numeric_limits<int>::min();

  if (-result >= max_int) {
    return max_int;
  }

  if (result <= min_int) {
    return min_int;
  }

  return negative ? int(result) : int(-result);
}

int main() {
	std::vector<std::string> sx = {"000234", "  12312", "-2323", "9999999999999999"};

	const std::string strs = "-- 123  asdf  asdf2 asdf sd as 123";
	std::istringstream iss(strs);
	std::string word;

	
	for(auto& str:sx)
		std::cout << myAtoi(str) << std::endl;
	return 0;
}
