#include<iostream>
#include<vector>
#include <algorithm>

int main() {
    std::vector<int> vec(5); // Create a vector of size 5
    int value = 0;

    std::generate(vec.begin(), vec.end(), [&value]() { return value += 2; }); // Initializes the vector with an arithmetic sequence starting from 2

    std::vector<int> rezero(5+2,0);
  

    // Print the vector

    std::cout << *(vec.end()) << std::endl;
    for(int v : rezero) {
        std::cout << v << " ";
    }

    for(auto v:rezero) {
      std::cout << v << std::endl;
    }

    return 0;
}



