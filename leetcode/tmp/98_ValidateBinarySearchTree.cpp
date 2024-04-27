#include "utils.h"


//Doesn't work
bool _isValidBST_fail(TreeNode* root, TreeNode* left, TreeNode* right) {
	if(!root)
		return true;

	if((left && left->val <= root->val) || (right && right->val >= root->val))
		return false;
	return _isValidBST_fail(left, left->left, left->right) && _isValidBST(right,right->left,right->right);
}

bool isValidBST_fail(TreeNode* root) {
	if(!root)
		return true;
	return _isValidBST_fail(root,root->left,root->right);
}
//

bool _isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) {
        return true;
    }

    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        return false;
    }

    return _isValidBST(root->left, minNode, root) && _isValidBST(root->right, root, maxNode);
}

bool isValidBST(TreeNode* root) {
    return _isValidBST(root, nullptr, nullptr);
}

int main() {
	return 0;
}
