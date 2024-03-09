#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:


    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxSum = INT_MIN, currSum = 0;
        for(auto num : nums) {
            currSum = std::max(num, currSum + num);
            maxSum = std::max(maxSum,currSum);
        }
        return maxSum; 
    }
};
