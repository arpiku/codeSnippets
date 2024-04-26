#include "utils.h"


void inorderTraversal(TreeNode *root, vecInt &inorder) {
  if (root == nullptr) {
    return;
  }
  inorderTraversal(root->left, inorder);
  inorder.push_back(root->val);
  inorderTraversal(root->right, inorder);
}
void postorderTraversal(TreeNode *root, vecInt& postorder) {
  if (root == nullptr) {
    return;
  }
  postorderTraversal(root->left, postorder);
  postorderTraversal(root->right, postorder);
  postorder.push_back(root->val);
}

void preorderTraversal(TreeNode *root, vecInt &preorder) {
  if (root == nullptr) {
    return;
  }
  preorder.push_back(root->val);
  preorderTraversal(root->left, preorder);
  preorderTraversal(root->right, preorder);
}

TreeNode* helper() {

  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->left->left = new TreeNode(10);
  root->left->left->left = new TreeNode(101);
  root->left->left->right = new TreeNode(102);

  root->left->right = new TreeNode(11);
  root->left->right->left = new TreeNode(55);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->left->left = new TreeNode(18);
  root->right->left->left->left = new TreeNode(21);
  root->right->right = new TreeNode(7);

  std::vector<int> post;
  std::vector<int> in;
  std::vector<int> pre;


  preorderTraversal(root, pre);
  inorderTraversal(root, in);
  postorderTraversal(root, post);

  printVec(pre);
  printVec(in);
  printVec(post);
  // printTreeGUI(root);
  return root;
  // deleteTree(root);
}
