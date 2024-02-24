
// One of the possible solutions
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        std::sort(nums.begin(),nums.end());
        return nums[N/2]; 
    }
};

//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> m;
        for(auto& i:nums) {
            m[i]++;
        }
        for(auto& k:m) {
            if (k.second > nums.size()/2) //This only works whith ">", with "=" one might get another value
                return k.first;
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false); // Trick to make thigns faster on leetcode board

        cin.tie(nullptr);
        cout.tie(nullptr);
        std::unordered_map<int,int> m;
        for(auto& i:nums) {
            m[i]++;
        }
        for(auto& k:m) {
            if (k.second > nums.size()/2)
                return k.first;
        }
        return -1;
    }
};
