class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) 
            return -1;
        int ans = 0;
        for(auto& i:nums)
            ans ^= i;
        return ans;

    }
};
