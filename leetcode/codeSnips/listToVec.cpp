
#include <vector>

template<typename T>
std::vector<T> convertToListNodeToVector(ListNode* head) {
    std::vector<T> vec;
    ListNode* current = head;
    while (current != nullptr) {
        vec.push_back(current->val);
        current = current->next;
    }
    return vec;
}
