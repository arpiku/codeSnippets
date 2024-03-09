class Solution {
public:
    void permute(std::vector<std::vector<int>>& res, std::vector<int>& nums, int l, int h) {
        if(l == h) {
            res.push_back(nums);
            return;
        };
        for(int i = l; i<=h; i++) {
            std::swap(nums[i],nums[l]);
            permute(res,nums,l+1,h);
            std::swap(nums[i],nums[l]);
        }


    };

    vector<vector<int>> permute(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        std::vector<std::vector<int>> res;
        permute(res,nums,l,h);
        return res;
    }
};
