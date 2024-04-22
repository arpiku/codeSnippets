#include"utils.h"

void _gp(std::vector<std::string>& res, std::string current, int openCount, int closeCount, int n) {
	if(current.length() == 2*n)	{
		res.push_back(current);
		return;
	}
	if(openCount < n) {
		_gp(res,current + '(', openCount+1, closeCount,n);
	}
	if(openCount > closeCount) {
		_gp(res,current + ')', openCount, closeCount+1,n);
	}
}

std::vector<std::string> generateParentheses(int N) {
	std::vector<std::string> res;
	_gp(res,"",0,0,N);
	return res;
}

// using namespa
int main() {
	std::vector<int> vv= {0,1,2,3,4};


	for(auto& i:vv) {
		std::vector<std::string> res = generateParentheses(i);
		printStrVec(res);	
	}

	return 0;
}



