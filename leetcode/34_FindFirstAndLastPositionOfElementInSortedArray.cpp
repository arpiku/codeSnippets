class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = std::find(nums.begin(),nums.end(),target);
        auto end = std::find(nums.rbegin(),nums.rend(),target);
        if(start == nums.end() || end == nums.rend())
            return {-1,-1};
        int i = std::distance(nums.begin(),start);
        int j = std::distance(nums.rbegin(),end);
        return {i,int(nums.size() - (j+1))};
    }
};
