#include <vector>
#include <algorithm>


// Merge sorts
std::vector<int> mergeSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size()); // Reserve space to improve efficiency
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    return result;
}

//Sorts, Merges and removes a given element
std::vector<int> mergeAndRemoveElement(const std::vector<int>& a, const std::vector<int>& b, int elementToRemove) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());
    std::vector<int> merged;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(merged));
    std::remove_copy(merged.begin(), merged.end(), std::back_inserter(result), elementToRemove);
    return result;
}

// Doesn't sort 
std::vector<int> quickMerge(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result = a; // Start with all elements from 'a'
    result.reserve(a.size() + b.size()); // Reserve space to improve efficiency
    std::copy(b.begin(), b.end(), std::back_inserter(result)); // Append 'b' to 'a'
    return result;
}

// A snippet to remove a given element from an array
void removeElement(std::vector<int>& vec, int element) {
        vec.erase(std::remove_if(vec.begin(),vec.end(),[element](int x){return x == element;}), vec.end());

// Following is a solution to
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
  

