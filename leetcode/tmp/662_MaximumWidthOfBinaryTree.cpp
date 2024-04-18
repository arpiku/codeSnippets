#include"utils.h"

    long widthOfBinaryTree(TreeNode* root) {
        std::queue<std::pair<TreeNode*,int>> queue;
        queue.push(std::make_pair(root,0)); //Root is a pos 1
        long maxWidth = 0;


        while(!queue.empty()) {
			long qSize = queue.size();
			long leftMost = queue.front().second;
			long  rightMost = leftMost;
            for(long i = 0; i<qSize; i++) {
                TreeNode* currNode = queue.front().first;
				long currNodePos = queue.front().second;
                queue.pop();
				rightMost = currNodePos;
                if(currNode->left)
                    queue.push(std::make_pair(currNode->left,2*currNodePos+1));
                if(currNode->right)
                    queue.push(std::make_pair(currNode->right,2*currNodePos+2));
            }
            maxWidth = std::max(maxWidth,rightMost - leftMost + 1);
        }

        return maxWidth;
        
    }

int widthOfBinaryTree_notWorking(TreeNode* root) { //This function does not work!!!
        std::queue<std::pair<TreeNode*,int>> queue;
        queue.push(std::make_pair(root,1)); //Root is a pos 1
        int maxWidth = std::numeric_limits<int>::min();


        while(!queue.empty()) {
						int qSize = queue.size();
						int leftMost = queue.front().second;
						int rightMost = leftMost;
            for(int i = 0; i<queue.size(); i++) {
                TreeNode* currNode = queue.front().first;
								int currNodePos = queue.front().second;
                queue.pop();

								rightMost = currNodePos;
                if(currNode->left)
                    queue.push(std::make_pair(currNode->left,2*currNodePos));
                if(currNode->right)
                    queue.push(std::make_pair(currNode->right,2*currNodePos+1));
            }
            maxWidth = std::max(maxWidth,rightMost - leftMost + 1);
        }

        return maxWidth;
        
    }

int main() {
	return 0;
}
