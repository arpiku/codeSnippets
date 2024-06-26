#include "utils.h"

int fmp(std::vector<int> &nums) { // This fails
  int missing = 1;
  for (int i = 0; i < nums.size(); ++i) {
    if (missing == nums.at(0)) // This code will fail when the arry is unsorted
      missing++;

    std::rotate(nums.begin(), nums.begin() + 1, nums.end());
  }
  return missing;
}

int firstMissingPositive_2(std::vector<int> &nums) {
  nums.erase(
      std::remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }),
      nums.end());
  // nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
  // //std::unique returns a pointers ForwardItr to
  // the beginning of the duplicate ranges

  // Mark positive integers as seen using the array itself
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] <= nums.size() && nums[i] != i + 1) {
      std::swap(nums[i], nums[nums[i] - 1]);
      if (nums[i] != nums[nums[i] - 1])
        --i; // Revisit swapped element
    }
  }

  // Find the first missing positive integer
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != i + 1)
      return i + 1;
  }

  return nums.size() + 1;
}


int firstMissingPositive_fail2(std::vector<int> &nums) {
  nums.erase(
      std::remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }),
      nums.end());
  // nums.erase(std::unique(nums.begin(),nums.end(),nums.end()));

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] <= nums.size() && nums[i] != i + 1) {

      std::swap(nums[i], nums[nums[i] - 1]);
      if (nums[i] != nums[nums[i] - 1])
        --i;
    }
  }

  for (int i = 0; i < nums.size(); ++i) {

    printVec(nums);

    if (nums[i] != i + 1)
      return i + 1;
  }

  return nums.size() + 1;
}

int firstMissingPositive_fail(std::vector<int> nums) {
  nums.erase(
      std::remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }),
      nums.end());

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] <= nums.size() && nums[i] != i + 1) {
      std::swap(nums[i], nums[nums[i] - 1]);
      if (nums[i] != nums[nums[i] - 1]) {
        --i;
      }
    }
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != i + 1)
      return i + 1;
  }

  return nums.size() + 1;
}

int firstMissingPositive_fail3(vecInt &nums) { //Leetcode gives some werid runtime error, otherwise working fine on
  //local system
  int n = nums.size();

  for (int i = 0; i < n; ++i) {
    if (n <= 0 || nums[i] > n) {
      nums[i] = n + 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    int num = std::abs(nums[i]);
    if (num <= n && nums[num - 1] > 0) {
      nums[num - 1] = -nums[num - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (nums[0] > 0) {
      return i + 1;
    }
  }
  return n + 1;
}

int main() {
  std::vector<int> v = {-1, 4, 2, 1, 9, 10};
  std::cout << " here " << std::endl;
  std::cout << firstMissingPositive_fail(v);
}
