#include"utils.h"

void printVec(std::vector<int>& vec) {
	std::cout << "[";
	for(auto& i:vec) 
		std::cout <<i << ",";
	std::cout << "-]" << std::endl;
}

void printStrVec(const std::vector<std::string>& vec) {
    if (vec.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }

    std::cout << "[" << vec.front();
    for (auto it = std::next(vec.begin()); it != vec.end(); ++it) {
        std::cout << "," << *it;
    }
    std::cout << "]" << std::endl;
}

ListNode* intVecToList(const std::vector<int>& vec) {
	ListNode* dummy = new ListNode(0);
	ListNode* current = dummy;

	for(auto& i:vec) {
		current->next = new ListNode(i);
		current = current->next;
	}
	ListNode* head = dummy->next;
	delete dummy;
	return head;
}

void printList(ListNode* head) {
	ListNode* dummy = head;
	while(dummy) {
		std::cout << dummy->val << "->";
		dummy=dummy->next;
	}
	std::cout<< "NULL" << std::endl;
}
