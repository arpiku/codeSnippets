#include<iostream>
#include<algorithm>
#include<vector>

std::vector<int> getRandomArray(size_t n) {
  std::vector<int> randomArrary(n,0);
  for(auto& i:randomArrary)
      i = rand()%1000;
  return randomArrary;
}

void printArray(const std::vector<int>& arr) {
  std::cout << "[";
  for(auto& i:arr)
    std::cout << i << ", ";
  std::cout << "]\n";
  return;
}
