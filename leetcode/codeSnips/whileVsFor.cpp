#include<string>
#include<algorithm>
#include<iostream>





int main() {
  std::string test = "thisisastring";
  int n = 2;
  int N = test.size();
  int idx = 0;

  while(idx + n - 1 < test.size()) {
    std::cout << idx << std::endl;
    std::cout << std::string(test.begin() + idx, test.begin()+idx+n) << std::endl;
    idx++;
  }
  std::cout << "--";
  for(int i = 0; i+n-1<test.size();i++) {
    std::cout << i << std::endl;
    std::cout << std::string(test.begin()+i, test.begin()+i+n);
  }

  std::vector<int> v1 = {1,1,2};
  std::vector<int> v2 = {1,1,2};
//  std::sort(v2.begin(),v)

  std::cout << bool(v1 == v2) << std::endl;

  

  return 0;
}
