
//The following I picked up from cpp reference
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    auto r_first = std::make_reverse_iterator(last);
    auto r_last = std::make_reverse_iterator(first);
    auto left = std::is_sorted_until(r_first, r_last);
 
    if (left != r_last)
    {
        auto right = std::upper_bound(r_first, left, *left);
        std::iter_swap(left, right);
    }
 
    std::reverse(left.base(), last);
    return left != r_last;
}

//Simpler version
//

bool nextPermutation(std::vector<int>& nums) {
    int k = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        std::reverse(nums.begin(), nums.end());
        return false;  // No next permutation (it was the last one), so we return to the first permutation.
    }

    int l = -1;
    for (int i = nums.size() - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }
    }

    std::swap(nums[k], nums[l]);
    std::reverse(nums.begin() + k + 1, nums.end());

    return true;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    
    nextPermutation(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}

