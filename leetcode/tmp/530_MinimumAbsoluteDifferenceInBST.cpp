#include"utils.h"
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
int getMinimumDifference(TreeNode* root) {
	int minDiff = std::numeric_limits<int>::max();
	TreeNode* prev = nullptr;

	std::function<void(TreeNode*,TreeNode*,int&)> findMinDiff = [&](TreeNode* node, TreeNode* prev, int& minDiff)->void {
		if(node == nullptr) return; //You wrote wrong code as you used "prev" instead of "node" to check for value
;
		findMinDiff(node->left,prev,minDiff);

		if(prev != nullptr) {
			std::cout << minDiff;
			minDiff = std::min(minDiff, std::abs(node->val - prev->val));
		}
		prev = node;

		findMinDiff(node->right,prev,minDiff);

	};
	
	findMinDiff(root,prev,minDiff);
	return minDiff;
}
