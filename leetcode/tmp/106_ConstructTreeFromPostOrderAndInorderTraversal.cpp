#include "utils.h"
#include "treeHelpers.h"

TreeNode* buildTree(vecInt inorder, vecInt postorder) {
  if(inorder.empty()) {
    return nullptr;
    }

  TreeNode* parent = new TreeNode(postorder[postorder.size()-1]);

  if(inorder.size() == 1) {
    return parent;
  }

  auto parentItr = std::find(inorder.begin(),inorder.end(),parent->val);

  vecInt rightSideInorder(parentItr+1,inorder.end());
  vecInt leftSideInorder(inorder.begin(),parentItr);

  vecInt rightSidePostorder(postorder.begin()+leftSideInorder.size(),postorder.end()-1);
  vecInt leftSidePostorder(postorder.begin(),postorder.begin()+leftSideInorder.size());

  parent->right = buildTree(rightSideInorder, rightSidePostorder);
  
  parent->left = buildTree(leftSideInorder, leftSidePostorder);

  return parent;

}

int main() {
  TreeNode* root = helper();

  printTreeGUI(root);
  vecInt in = {101,10,102,9,55,11,3,21,18,15,20,7};
  vecInt post = {101,102,10,55,11,9,21,18,15,7,20,3};
  TreeNode* broot = buildTree(in,post);
  printTreeGUI(broot);
  
  deleteTree(root);
  return 0;
}
