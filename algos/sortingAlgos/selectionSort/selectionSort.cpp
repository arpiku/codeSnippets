#include<iostream>
#include<algorithm>
#include<vector>

void selectionSort(std::vector<int>& vec) {
  for (int i = 0; i<=vec.size()-1; ++i) {
  auto minItrAssumed = (vec.begin() + i);
  auto minItr = std::min_element(vec.begin()+i, vec.end());
  if(minItrAssumed != minItr)
    std::swap(*minItrAssumed,*minItr);
  }
}


int main() {
  std::cout << "Running" << std::endl;
return 0;
}
