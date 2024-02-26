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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root; 
    }
};

//BFS Solution
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        std::queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        while(!nodeQ.empty()) {
            TreeNode* curr = nodeQ.front();
            nodeQ.pop();
            std::swap(curr->left,curr->right);
            if(curr->left)
                nodeQ.push(curr->left);
            if(curr->right)
                nodeQ.push(curr->right);
        }
        return root;   
    }
};
