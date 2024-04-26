#include "utils.h"
#include "treeHelpers.h"

void _zigzag(TreeNode* node, vec2dInt& res, bool dir) {
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
		if(dir) {
			std::reverse(current.begin(),current.end());
		}
		res.push_back(current);
		dir = !dir;
	}
}

vec2dInt zigzagLevelOrder(TreeNode* root) {
	if(!root)
		return {};
	vec2dInt res;
	_zigzag(root,res,0);
	return res;
}

int main() {
TreeNode* root = helper();
vec2dInt res = zigzagLevelOrder(root);
deleteTree(root);
printVec(res);
return 0;	
}
