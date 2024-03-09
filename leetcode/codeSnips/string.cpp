#include<string>
#include<vector>
#include<iostream>


std::vector<std::string> splitString(const std::string& s, int n) {
    std::vector<std::string> result;
    int length = s.length();

    for (int i = 0; i < length; i += n) {
        result.push_back(s.substr(i, std::min(n, length - i)));
    }

    return result;
}

int main() {
  std::string ss = "thisisastring";
  std::vector<std::string> v = splitString(ss,2);

  for(auto& s:v)
    std::cout << s << std::endl;

return 0;
}
