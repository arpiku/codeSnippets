
//A dfs solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return std::max(1+maxDepth(root->right), 1+maxDepth(root->left));
        
    }
};

// A bfs Solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        std::queue<TreeNode*> q;
        uint height = 0; 
        q.push(root);
        while(!q.empty()) {
            int lvlwidht = q.size();
            for(int i =0; i<lvlwidht; i++) {
                TreeNode* tn = q.front();
                q.pop();
                if(tn->left) 
                    q.push(tn->left);
                if(tn->right)
                    q.push(tn->right);
            }

            height++;
        }
        return height;
    }
};
