#include"utils.h"

ListNode *reverseList(ListNode *head) {
  if (!head || !head->next)
    return head;
  ListNode *newHead = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

std::tuple<ListNode *, ListNode *> splitList(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *right = slow->next;
  slow->next = NULL;
  return std::make_tuple(head, right);
}

ListNode *merge(ListNode *left, ListNode *right, bool side) {
  if (!left)
    return right;
  if (!right)
    return left;
  ListNode *result = nullptr;

  if (side) {
    result = left;
    result->next = merge(left->next, right, !side);
  } else {
    result = right;
    result->next = merge(left, right->next, !side);
  }
  return result;
}

void reorderList(ListNode *head) {
  if(!head || !head->next)
    return;
  auto [left, right] = splitList(head);
  right = reverseList(right);
  head = merge(left, right, 1);
}

int main() {
  std::vector<int> vv = {1,2,3,4};
  ListNode* head = intVecToList(vv);
  reorderList(head); 

  printList(head);
  return 0;  
}
