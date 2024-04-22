#include"utils.h"
#include <queue>

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val > list2->val) {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        else  {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
    }

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
  if(lists.size() == 0)  
    return nullptr;
  if(lists.size() == 1)
    return lists[0];
  ListNode* merged = mergeTwoLists(lists[0],lists[1]);
  for(int i = 2; i<lists.size(); i++) {
    merged = mergeTwoLists(merged,lists[i]);
  }
  return merged;
}


/*This problem also may be solved using minHeap */

struct Compare {
  bool operator()(const ListNode *a, const ListNode *b) {
    return a->val > b->val;
  }
};

ListNode *mergeKSortedListsMinHeap(const std::vector<ListNode *> &lists) {
  auto cmpFunc = [](ListNode *a, ListNode *b) { return a->val > b->val; };
  std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmpFunc)>
      minHeap(cmpFunc);
  for (auto head : lists) {
    if (head)
      minHeap.push(head);
  }

  ListNode *dummy = new ListNode(0);
  ListNode *current = dummy;

  while (!minHeap.empty()) {
    ListNode *smallest = minHeap.top();
    minHeap.pop();
    current->next = smallest;
    current = current->next;
    if (smallest->next)
      minHeap.push(smallest->next);
  }
  ListNode *head = current; // One could just declare the ListNode on stack to
                            // avoid using the two extra variables
  delete dummy;
  return head;
}

int main() {
  std::vector<std::vector<int>> vv = {{1,4,5},{1,3,4},{2,6}};
  std::vector<ListNode*> lists = {};

  for(auto& v: vv) {
    lists.push_back(intVecToList(v));
  }

  for(auto& l:lists) {
    printList(l);    
  }

  ListNode* merged = mergeKLists(lists);
  printList(merged);
  
  
  return 0;
}
