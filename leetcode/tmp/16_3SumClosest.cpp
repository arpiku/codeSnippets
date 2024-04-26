#include "utils.h"

int threeSumClosest(vecInt &nums, int target) {
  if (nums.size() < 3) {
    return 0;
  }

  std::sort(nums.begin(), nums.end());

  int closest = std::numeric_limits<int>::max();
  int minDiff = std::numeric_limits<int>::max();
  int n = nums.size();

  for (int i = 0; i < n - 2; ++i) {
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      int diff = std::abs(sum - target);
      if (diff < minDiff) {
        minDiff = diff;
        closest = sum;
      }
      if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
  }

  return closest;
}

int main() {
  std::vector<int> vv = {-1, 2, 1, -4};
  int closest = threeSumClosest(vv, 1);
  LOG(closest);

  return 0;
}
