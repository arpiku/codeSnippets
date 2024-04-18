#include"utils.h"

int main() {
	std::set<char> ss;
	ss.insert('a');
	ss.insert('b');
	
	ss.insert('a');
	ss.insert('c');

	for(auto& v:ss) {
		std::cout << v << std::endl;
	}

	return 0;
}
