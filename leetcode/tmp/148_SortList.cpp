#include "utils.h"

ListNode* merge(ListNode *right, ListNode *left) {
  if (!left)
    return right;
  if (!right)
    return left;
  ListNode* result = nullptr;
  if (left->val <= right->val) {
    result = left;
    result->next = merge(left->next, right);
  } else {
    result = right;
    result->next = merge(left, right->next);
  }
  return result;
}

std::tuple<ListNode*,ListNode*> splitList(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head->next;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode* right = slow->next;
  slow->next = nullptr;
  return std::make_tuple(head,right);
}

ListNode* sortList(ListNode* head) {
  if(!head || !head->next) 
    return head;

  auto [right,left] = splitList(head);
  ListNode* leftSorted = sortList(left);
  ListNode* rightSorted = sortList(right);

  return merge(leftSorted,rightSorted);
}

int main() {
  
  std::vector<int> vv = {3,42,423,12,1,34,6,234} ;
  ListNode* head = intVecToList(vv);
  printList(head);
  ListNode* sorted = sortList(head);
  printList(sorted);

  return 0;
}
