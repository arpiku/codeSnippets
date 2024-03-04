
#include <iostream>
#include <vector>
#include <algorithm>

void moveToBack(std::vector<int>& vec, int value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        std::rotate(it, it + 1, vec.end());
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 3, 6};

    moveToBack(vec, 3); // Move the first occurrence of 3 to the back

    for (int n : vec) {
        std::cout << n << " ";
    }

    return 0;
}
