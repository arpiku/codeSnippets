
//The follwoing code is wrong
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1000);
        ListNode* res = dummy;

        ListNode* itr = head;

        while(itr && itr->next) {
        
            while(itr->val == itr->next->val && itr->next) {
                itr = itr->next;
            } itr = itr->next;

                dummy->next = itr;
                itr = itr->next;
                dummy = dummy->next;
        }
        return res->next;
        
    }
};

//This is correct 
//

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; // If the list is empty, return null.

        ListNode* dummy = new ListNode(-1); // Dummy node to help with edge cases.
        ListNode* tail = dummy; // Tail will be used to build the new list without duplicates.

        ListNode* itr = head; // Iterator to go through the original list.
        while (itr) {
            if (itr->next && itr->val == itr->next->val) {
                // Skip over all nodes that have the same value.
                while (itr->next && itr->val == itr->next->val) {
                    itr = itr->next;
                }
            } else {
                // If current node is unique, link it to the tail of the new list.
                tail->next = itr;
                tail = itr; // Move the tail pointer forward.
            }
            itr = itr->next; // Move to the next node.
        }

        tail->next = nullptr; // Ensure the last node of the new list points to nullptr.
        ListNode* res = dummy->next; // The head of the new list.
        delete dummy; // Clean up the dummy node.
        return res;
    }
};
