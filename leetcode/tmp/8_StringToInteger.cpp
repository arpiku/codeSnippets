#include "utils.h"


int myAtoiFail(std::string s) {
  bool negative = false;
  long result = 0;
  int isWordBeforeNum = 0;

  for (auto &ch : s) {
    if (std::isspace(ch) || ch == '+')
      continue;
    if (ch == '-') {
      negative = true;
      }
    if (std::isdigit(ch)) {
      if(isWordBeforeNum > 0) {
        return 0;
      }
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

int myAtoi(std::string s) {
    bool negative = false;
    long result = 0;
    bool numStarted = false;

    for (char ch : s) {
        if (std::isspace(ch)) {
            if (numStarted) {
                break;  
            }
            continue;  
        }

        if (ch == '+' || ch == '-') {
            if (numStarted) {
                break;              }
            negative = (ch == '-');
            numStarted = true;
            continue;  
        }

        if (std::isdigit(ch)) {
            numStarted = true;
            int digit = ch - '0';
            result = result * 10 + digit;

            if (result > std::numeric_limits<int>::max()) {
                return (negative) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
            }
        } else {
            // Non-numeric character encountered, stop parsing
            break;
        }
    }

    return (negative) ? -static_cast<int>(result) : static_cast<int>(result);
}

int main() {
  return 0;
}
