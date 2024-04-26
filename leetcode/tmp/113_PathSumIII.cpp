#include "utils.h"

void _pathFinder(TreeNode* node, int target, vecInt current, vec2dInt& res) {
	if(!node)
		return;
	if(target - node->val == 0 && !node->right && !node->left) {
		current.push_back(node->val);
		res.push_back(current);
		return;
	}
	int remainder = target - node->val;
	current.push_back(node->val);
	if(node->left) 
		_pathFinder(node->left,remainder,current,res);	
	if(node->right) 
		_pathFinder(node->right,remainder,current,res);	
	return;
}

vec2dInt pathSum(TreeNode* root, int targetSum) {
	if(!root)
		return {};
	vec2dInt res;
	_pathFinder(root, targetSum, {},res);
	return res;
}

int main() {
	vecInt vv = {5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1};
	vecInt vv2 = {1,2};
	TreeNode* root = intVecToBinaryTree(vv2);
	vec2dInt res = pathSum(root,1);
	printVec(res);

	return 0;
}
