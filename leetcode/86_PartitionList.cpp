class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create two new lists to separate values less than x and values greater or equal to x
        ListNode lessHead(0), greaterHead(0); // Temporary dummy heads
        ListNode *lessPtr = &lessHead, *greaterPtr = &greaterHead;
        
        while (head) {
            if (head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            head = head->next;
        }
        
        // Combine the two lists
        lessPtr->next = greaterHead.next;
        greaterPtr->next = nullptr; // Important to avoid cyclic links
        
        return lessHead.next; // Return the head of the modified list
    }
};


// My solution
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
    ListNode* partition(ListNode* head, int x) {
        ListNode gth(0), lth(0);
        ListNode *lPtr = &lth, *gPtr = &gth;

        while(head) {
            if(head->val < x) {
                lPtr->next = head;
                lPtr = lPtr->next;
            } else { 
                gPtr->next  = head;
                gPtr = gPtr->next;
            }
            head = head->next;
        } 

        lPtr->next = gth.next;
        gPtr->next = nullptr;
        
        return lth.next;
        
    }
};

// Remember the stable partion thing ---------
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
    ListNode* partition(ListNode* head, int x) {
        std::vector<int> v;
        ListNode* store = head;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        std::stable_partition(v.begin(),v.end(), [&x](int i) { return i < x;});
        head = store;
        auto itr = v.begin();
        while(head) {
            head->val = *itr;
            itr++;
            head = head->next;
        }

        return store;
        
    }
};
