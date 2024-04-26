#include "utils.h"
#include "treeHelpers.h"

void _lvlOrderTraversal(TreeNode* node, vec2dInt& res) {
	std::queue<TreeNode*> nodeQ;
	nodeQ.push(node);
	while(!nodeQ.empty()) {
		size_t len = nodeQ.size();
		vecInt current = {};
		for(int i = 0; i<len; i++) {
				TreeNode* curr = nodeQ.front();
				nodeQ.pop();
				current.push_back(curr->val);
				if(curr->left) {
				nodeQ.push(curr->left);
			}
				if(curr->right) {
				nodeQ.push(curr->right);
			}
		}
		res.push_back(current);
	}
}

vec2dInt levelOrder(TreeNode* root) {
	if(!root)
		return {};
	vec2dInt res;
	_lvlOrderTraversal(root,res);
	return res;
}

int main() {
TreeNode* root = helper();
vec2dInt res = levelOrder(root);
deleteTree(root);
printVec(res);
return 0;	
}
