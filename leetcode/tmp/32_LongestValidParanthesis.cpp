#include"utils.h"

using namespace std;

int longestValidParentheses(string s) {
	std::stack<int> stk;
	stk.push(-1);

	int longest = 0;

	for(int i=0; i<s.length(); ++i) {
		if(s[i] == '(') {
			stk.push(i);
		} else {
			stk.pop();
			if(stk.empty()) {
				stk.push(i);
			} else {
				longest = std::max(longest,i-stk.top());
			}
		}

		
	}
return longest;        
}


int main() {
	std::string test = "(())())";
	std::cout << longestValidParentheses(test);
		
	return 0;
}
