#include "utils.h"



std::vector<std::string> letterCombinations(std::string digits) {
	if(digits.empty())
		return {};
	std::vector<std::string> result;
	std::vector<std::string> numToChars = {
		"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

	std::string current = "";

	std::function<void(int)> generateCombinations = [&](int index) {
		if(digits.size() == index) {
			result.push_back(current);
			return; 
		}
		std::string letters = numToChars[digits[index]-'0'];
		for(char ch:letters) {
			current.push_back(ch);
			generateCombinations(index+1);
			current.pop_back();
		}
	};
	generateCombinations(0);
	return result;
}


int main() {
	std::vector<std::string> vecStr = letterCombinations("23");
	printStrVec(vecStr);
	return 0;
}
