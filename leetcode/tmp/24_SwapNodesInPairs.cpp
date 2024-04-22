#include"utils.h"

ListNode* swapPairs_val(ListNode* head) { //This works but is not the acceptable solution
  if (!head || !head->next)
    return head;
  ListNode* iter = head;
  while(iter && iter->next) {
    std::swap(iter->val, iter->next->val);
    iter = iter->next->next;
  }
 return head;
}

ListNode* swapPairs(ListNode* head) {
  if(!head || !head->next) {
    return head;
  }

 return head;
}


int main() {
  std::vector<int> v = {1,2,3,4,5};
  std::vector<int> v2 = {1,2};
  ListNode* head = intVecToList(v2);
  printList(head);
  head = swapPairs(head);
  printList(head);

  return 0;

}
