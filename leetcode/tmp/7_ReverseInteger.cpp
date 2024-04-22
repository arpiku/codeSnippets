#include"utils.h"



int reverse(int x) {
	auto INT_MAX = std::numeric_limits<int>::max();
	auto INT_MIN = std::numeric_limits<int>::min();

        long reverse = 0;
        while(x) {
            if(reverse >= INT_MAX || reverse <= INT_MIN)
                return 0;
            int digit = x%10; 
            reverse = reverse*10 + digit;
            x /= 10;
        }
        if(reverse >= INT_MAX || reverse <= INT_MIN)
                return 0;
        return int(reverse);
        
    }

int main() {
	
	std::vector<int> test =  {1534236469,451,132};
	std::vector<int> res = {};
	printVec(test);
	for(auto i:test) {
		res.push_back(reverse(i));
	}
	printVec(res);



	
	return 0;	
}
