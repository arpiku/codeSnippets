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

void printVec(std::vector<int> vec);
