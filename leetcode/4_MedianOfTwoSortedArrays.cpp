class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        std::vector<int> res;
        std::merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(), std::back_inserter(res));
        const int n = res.size();
        for(auto& i:res)
            std::cout << i << ",";
        if(res.size()%2 == 0)
            result = (res[n/2 - 1] + res[n/2])/2.0f;
        else 
            result = res[int(n/2)];
        
        return result;
    }
    

};
