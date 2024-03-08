
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};
    std::set<int> set3 = {4, 5, 6, 7, 8};
    std::vector<std::set<int>> sets = {set1, set2, set3};

    std::set<int> intersection = sets[0];  // Start with the first set

    for (size_t i = 1; i < sets.size(); ++i) {
        std::set<int> temp_intersection;
        std::set_intersection(intersection.begin(), intersection.end(),
                              sets[i].begin(), sets[i].end(),
                              std::inserter(temp_intersection, temp_intersection.begin()));
        intersection = std::move(temp_intersection);  // Update the running intersection
    }

    std::cout << "Intersection of all sets: ";
    for (int elem : intersection) {
        std::cout << elem << " ";
    }

    return 0;
}
