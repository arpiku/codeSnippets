class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minL = std::numeric_limits<int>::max();
        int sum = 0;
        int left = 0;
        for(int right = 0; right < n; ++right) {
            sum += nums[right];
            while(sum >=target) {
                minL = std::min(minL, int(right-left+1));
                sum -= nums[left++];
            }
        }

        return minL != std::numeric_limits<int>::max() ? minL : 0;
        
    }
};
