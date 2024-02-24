#include <algorithm> // For std::sort
#include <vector>
#include <iostream>

int main() {
    // Example: vector of vectors
    std::vector<std::vector<int>> vec = {{1, 4, 2}, {4, 1, 3}, {4, 5, 1}};

    // Sort the vector of vectors based on the last element of each vector
    std::sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.back() < b.back(); // Compare based on the last element
    });

    // Print the sorted vector of vectors
    for (const auto& innerVec : vec) {
        for (int elem : innerVec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
