class Solution {
public:
 
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> pQ;
        for(auto& i:nums) 
            pQ.push(i);
        for(int i = 0; i<k-1; i++) {
            pQ.pop();
        }
        return pQ.top();
    }
};
