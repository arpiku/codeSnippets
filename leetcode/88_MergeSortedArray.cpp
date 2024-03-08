// A C like solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(j>=0) {
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

// Using std library
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> result;
        result.reserve(m+n); 
        std::merge(nums1.begin(),nums1.begin()+m,nums2.begin(),nums2.end(), std::back_inserter(result));
        nums1 = result;
        return;
    }
};


#include <vector>
#include <algorithm> // For std::copy
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        auto nums1End = nums1.begin() + m; // Iterator to the end of the initialized part of nums1
        auto nums2End = nums2.begin() + n; // Iterator to the end of nums2
        
        auto dest = nums1.rbegin(); // Reverse iterator to the end of nums1's total capacity
        auto i = std::make_reverse_iterator(nums1End); // Reverse iterator to the last initialized element of nums1
        auto j = nums2.rbegin(); // Reverse iterator to the last element of nums2
        
        while (j != nums2.rend()) {
            if (i != nums1.rend() && *i > *j) {
                *dest++ = *i++;
            } else {
                *dest++ = *j++;
            }
        }
    }
};

