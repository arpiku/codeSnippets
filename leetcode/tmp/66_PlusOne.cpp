#include "utils.h"

std::vector<int> plusOne(std::vector<int> digits) {
  if(digits[digits.size() - 1] < 9) {
    digits[digits.size() - 1]++;
    return digits;
  }

  auto digit = digits.rbegin();
  while(digit != digits.rend()) {
    if(*digit + 1 < 10) {
      *digit = *digit + 1;
      break;
    }
    *digit = (*digit + 1)%10;
    digit++;
  }   
  if(digit == digits.rend()) {
    digits.push_back(1);
    std::rotate(digits.rbegin(),digits.rbegin()+1,digits.rend());
 }
    
  return digits;
}

int main() {
  std::vector<int> vv = {9,9,9,9};
  std::vector<int> res = plusOne(vv);
  printVec(res);
  return 0;  
}
