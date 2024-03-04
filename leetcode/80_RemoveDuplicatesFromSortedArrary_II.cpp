class Solution {
public:
    int _removeDuplicates(vector<int>& nums, size_t repition) {
        if(nums.size() <= repition) return nums.size();

        int writeIdx = repition;
        for(int i = repition; i<  nums.size(); i++) {
            if(nums[i] != nums[writeIdx-repition]) {
                nums[writeIdx++] = nums[i];
            }
        }
        return writeIdx;
    }
    int removeDuplicates(vector<int>& nums) {
        return _removeDuplicates(nums,2);
    }
};
