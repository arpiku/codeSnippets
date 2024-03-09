class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || nums.front() > target)
            return 0;
        if(*(nums.end()-1) < target)
            return nums.size();
        
        
        auto it = std::find(nums.begin(),nums.end(),target);
        if(it != nums.end()) {
            return int(it - nums.begin());
        }
        nums.push_back(target);
        std::sort(nums.begin(),nums.end());
        it = std::find(nums.begin(),nums.end(),target);
    return int(it - nums.begin());
    }
};
