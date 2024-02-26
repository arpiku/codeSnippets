/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return std::max(1+getHeight(root->left), 1+ getHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getHeight(root->right) - getHeight(root->left))>1) return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};


