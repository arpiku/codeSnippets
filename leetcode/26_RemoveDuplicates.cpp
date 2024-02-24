
// One possible solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto duplicateStart =  std::unique(nums.begin(),nums.end());
        nums.erase(duplicateStart,nums.end());
        return nums.size();
    }
};

// A faster solution
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      std::set<int> uniqElements(nums.begin(),nums.end());
      nums.assign(uniqElements.begin(),uniqElements.end());
      return uniqElements.size();
    }
}

//An old style solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(i < nums.size()-1 && nums[i] == nums[i+1])
                continue;
            nums[idx++] = nums[i];
            
        }
        return idx;
        
    }
};
