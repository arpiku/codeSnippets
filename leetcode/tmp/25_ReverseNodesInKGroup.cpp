#include "utils.h"


ListNode* reverseLinkedList(ListNode* head) {
  if(!head || !head->next) 
    return  head;

  ListNode* newHead = reverseLinkedList(head->next); // See how recursion ends up returning the result of the last call

  head->next->next = head;
  head->next = NULL;
  return newHead;
}

ListNode* getKthNode(ListNode* head, int k) {
  ListNode* curr = head;
  for(int i = 0; i<k-1; ++i) {
    curr = curr->next;
  }
  return curr;
}


ListNode* reverseKGroup(ListNode* head, int k, int length) {
  if(k>length) 
    return head;
  ListNode* currHead = head;
  ListNode* tail = getKthNode(head,k);
  ListNode* nextHead = tail->next;
  tail->next = nullptr;
  head = reverseLinkedList(head);
  currHead->next = reverseKGroup(nextHead,k,length-k);
  return head;
}



int main() {

  std::vector<int> v = {1,2};
  ListNode* head = intVecToList(v);
  printList(head);
  head = reverseKGroup(head,2,v.size());
  printList(head);


  

  return 0;
}  


   

