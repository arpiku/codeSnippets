

//ONe solution 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {    
        int idx = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }

};

//My preferred on 

class Solution  {
	public:
		int removeElement(vector<int>& nums, int val) {
			nums.erase(std::remove_if(nums.begin(),nums.end(),[val](int x) {return x == val;}), nums.end());
			return nums.size();
		}

	};
