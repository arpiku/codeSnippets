#include"utils.h"


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
  std::optional<int> zipAdd(ListNode* l1, ListNode* l2, int carry) {
    if(l1 && l2) {
      return l1->val + l2->val + carry;
    }
    if(l1) {
      return l1->val + carry;
    }
    if(l2) {
      return l2->val + carry;
    }
    if(carry)
      return carry;

    return std::nullopt;
  }

 ListNode* linkStep(ListNode* l) {
  if(!l)
    return nullptr;
  return l->next;
  }
    
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* dummy = new ListNode(0);
  ListNode* head = dummy;
  int carry = 0;
  while(auto sum = zipAdd(l1,l2,carry)) {
   dummy->next = new ListNode(*sum % 10);
    carry = (*sum >= 10) ? 1 : 0;
    l1 = linkStep(l1);
    l2 = linkStep(l2);
    dummy = dummy->next;
  }

  return head->next;
}

  ListNode* makeList(const std::vector<int>& v) {
  ListNode* dummy = new ListNode(0);
  ListNode* head = dummy;
  for(auto& i:v) {
    dummy->next = new ListNode(i);
    dummy = dummy->next;
  }

  return head->next;
}

void printList(ListNode* l) {
    std::cout << "[";
  while(l) {
    std::cout << l->val << ",";
    l = linkStep(l);
  }

    std::cout << "]";
}


int main() {
  std::vector<int> v2 = {9,9,9};
  std::vector<int> v = {5,5};


  ListNode* list1 = makeList(v);
  ListNode* list2 = makeList(v2);

  printList(list1);
  printList(list2);

  ListNode* ll= addTwoNumbers(list1,list2 );

  printList(ll);
 
  return 0;
}
      

        
        
   
