#pragma once

#include<vector>
#include<iostream>
#include<optional>
#include<functional>
#include<string>
#include<algorithm>
#include<iterator>
#include<stack>
#include<tuple>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<limits>
#include<numeric>
#include<compare>
#include<sstream>
#define LOG(x) std::cout << x << std::endl;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printVec(std::vector<int>& vec);
void printStrVec(const std::vector<std::string>& vec);

void printList(ListNode* head);

// std::vector<int> makeIntVector(std::fucntion<int(int)> )

ListNode* intVecToList(const std::vector<int>& vec);

// int getListLength(ListNode* head) {
// size_t length = 0;
// ListNode* iter = head;
// while(iter) {
//     length++;
//     iter = iter->next;
// }
// return length;
// }
