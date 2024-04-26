#include "utils.h"


bool _pathFinder(TreeNode* node, int sum, const int& targetSum) {
	if(!node) 
		return false;
	sum += node->val; //Positioning of this statement mattters;
	if(!node->right && !node->left) {
		return sum == targetSum ;
	}
	return 	_pathFinder(node->left,sum,targetSum) ||  _pathFinder(node->right,sum,targetSum);	
}

bool hasPathSum(TreeNode* root, int targetSum) {
	if(!root)
		return false;
	return _pathFinder(root,0, targetSum);
}

int main() {
	vecInt vv = {5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1};
	vecInt vv2 = {1,2};

	TreeNode* root = intVecToBinaryTree(vv);

	std::cout << hasPathSum(root,22) << std::endl;

	return 0;
}
