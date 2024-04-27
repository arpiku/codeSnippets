#include "utils.h"

ListNode* reverseLinkedList(ListNode* head) {
	if(!head || !head->next)
		return head;
	ListNode* newHead = reverseLinkedList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newHead; 
}




ListNode* reverseBetween(ListNode* head, int left, int right) {
	if(!head || !head->next)
		return head;

	ListNode* prev = new ListNode(0);
	prev->next = head;
	ListNode* revertHead = head;
	while(left > 1) {
		revertHead = revertHead->next;
		prev = prev->next;
		left--;
	}
	prev->next = nullptr;

	ListNode* tail = revertHead;
	ListNode* tail2 = revertHead;
	right = right - left;
	while(right > 0) {
		tail = tail->next;
		right--;
	}
	ListNode* afterTail = tail->next;
	tail->next = nullptr;

	revertHead = reverseLinkedList(revertHead);
	prev->next = revertHead;
	tail2->next = afterTail;
	return prev;
}



int main() {
	std::vector<int> vv = {1,2,4,5,6};
	ListNode* head = intVecToList(vv);
	head = reverseBetween(head,2,5);
	printList(head);

	return 0;
}
