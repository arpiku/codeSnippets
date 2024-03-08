int search(const std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Determine if the left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // The right half must be sorted
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1; // Target is not found
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = std::find(nums.begin(),nums.end(),target);
        auto index = std::distance(nums.begin(),iter);
        if(index == nums.size())
            return -1;
        return index;

    }
};
