#include"utils.h"

//goal is to find all the subarray that have sum == k
//Here the goal is not to find the subarray but just to find the number of possible combination


// [1,1,1] -- 2,3

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> sumCount; //what does this map store? 
  // count of way a particular sum can be achieved, sumPossibleSetCount
    int count = 0;
    int sum = 0;

    sumCount[0] = 1; // Initialize with 0 sum to handle subarrays starting from index 0

    for (int num : nums) {
        sum += num; 
        if (sumCount.find(sum - k) != sumCount.end()) {
            count += sumCount[sum - k];
        }
        sumCount[sum]++;
    }

    return count;
}
