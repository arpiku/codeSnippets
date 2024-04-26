#include "utils.h"

void flatten(TreeNode* root) {
	if(!root)
		return;
	flatten(root->left);
	flatten(root->right);

	TreeNode* rightSave = root->right;
	root->right = root->left;
	root->left = nullptr;

	TreeNode* current = root;
	while(current->right) { 
		current = current->right;
	}
	current->right = rightSave;
	return;
}



int main() {
	std::vector<int> vv = {1,2,5,3,4,INT_MAX,6};
	TreeNode* root = intVecToBinaryTree(vv);
	printTreeGUI(root);
	flatten(root);
	printTreeGUI(root);
	deleteTree(root);


	
	return 0;
}
