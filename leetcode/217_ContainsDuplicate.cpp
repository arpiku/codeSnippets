
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto& i:nums) {
            m[i]++;
            if(m[i] > 1)
                return true;
        }
        return false;
    }
};

- The following uses sorting


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        auto itr = nums.begin();
        while(itr+1 != nums.end()) {
            if(*itr == *(++itr))
                return true; 

        }
        return false;
    }
};




