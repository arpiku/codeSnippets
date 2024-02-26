/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode steadyHead(0);
        ListNode* curr = &steadyHead;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1)
            curr->next = l1;
        if(l2)
            curr->next = l2;
        return steadyHead.next;

    }
};

// Recursive Solution
//
class Solution {
public:
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
};

