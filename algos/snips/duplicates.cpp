#include<iostream>
#include<algorithm>
#include<vector>

void getUnique(std::vector<int>& vec) {
  std::unique(vec.begin(),vec.end());
  return;
}

int main() {
  std::vector<int> vec = {0,0,1,1,1,1,2,2,3,4,6};
  getUnique(vec);
  for(auto& i:vec) {
    std::cout << i << ", " <<std::endl;
  }
  return 0;
}
