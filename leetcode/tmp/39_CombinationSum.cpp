#include"utils.h"

using namespace std;
vector<vector<int>> combinationSum(vector<int>& nums, int target) {

  vector<vector<int>> result;
  std::sort(nums.begin(),nums.end());

  std::function<void(int, vector<int>&, int)> backtrack = [&](int index, vector<int>& current, int remaining ) {
    if(remaining == 0) {
      result.push_back(current);
      return;
    }

    for(int i = index; i < nums.size(); ++i) {
      if(nums[i] <= remaining) {
        current.push_back(nums[i]);
        backtrack(i, current, remaining-nums[i]);
        current.pop_back();
      }
    }
  };

  vector<int> current;
  backtrack(0,current,target);
  return result;
}    



void printVecOfVec(std::vector<std::vector<int>>& v) {
    for (const auto& i : v) {
        std::cout << "[";
        std::copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, ", "));
        std::cout << "\b\b] ";
    }
    std::cout << std::endl;
}


int main() {
std::vector<int> v = {2,3,5,7};
int target = 7;


return 0;
}
