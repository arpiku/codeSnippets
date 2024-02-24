#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> constructProductArray(const std::vector<int>& nums) {
    std::vector<int> productArray(nums.size(), 1);
    int product = 1;

    for (size_t i = 0; i < nums.size(); ++i) {
        productArray[i] = product;
        product *= nums[i];
    }

    return productArray;
}

int main() {
    std::vector<int> nums = {0, 1, 5, 0, 5};
    std::vector<int> productArray = constructProductArray(nums);

    for (int prod : productArray) {
        std::cout << prod << " ";
    }
    std::cout << std::endl;

    return 0;
}

