#include"utils.h"

using namespace std;
int findMaxLength(std::vector<int>& nums) { //This code fails for the input of [0,1,1,0,1,1,1,0]
    std::unordered_map<int, int> diffMap;
    diffMap[0] = -1; // Initialize with a cumulative difference of 0 at index -1
    int maxLength = 0; //We use -1 because 0 is the cumulitive difference is what we are actually looking for.
    int cumulativeDiff = 0;

    for (int i = 0; i < nums.size(); ++i) {
        cumulativeDiff += (nums[i] == 0) ? -1 : 1; //The intent here is to measure the overall difference 
        //between observed counts of 0 and 1.

        if (diffMap.count(cumulativeDiff) > 0) {
            maxLength = std::max(maxLength, i - diffMap[cumulativeDiff]);
        } else {
            diffMap[cumulativeDiff] = i;
        }
    }

    return maxLength;
}

int findMaxLength_2(const std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    int maxLen = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); ++i) {
        count += (nums[i] == 0) ? -1 : 1;

        if (count == 0) {
            maxLen = std::max(maxLen, i + 1);
        } else if (countMap.find(count) == countMap.end()) {
            countMap[count] = i;
        } else {
            maxLen = std::max(maxLen, i - countMap[count]);
        }
    }

    return maxLen;
}
