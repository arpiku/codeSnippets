#include <exception>
#include<iostream>
#include <stdexcept>
#include<vector>

int main() {
  std::vector<std::vector<int>> mat = {{1,2},{3,4}};

  try {
    std::cout << mat.at(-1).at(-1);
  }
  catch (const std::out_of_range& e) {

    std::cout << std::string(e) << std::endl;
  }

  return 0;

}
