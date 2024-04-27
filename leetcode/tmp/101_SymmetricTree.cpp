#include "utils.h"
bool _isSymmetric(TreeNode *left, TreeNode *right) {
  if (!left && !right)
    return true;
  if (!left || !right)
    return false;

  return (left->val == right->val) && _isSymmetric(left->left, right->right) &&
         _isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
  if (!root) {
    return true;
  }
  return _isSymmetric(root->left, root->right);
}

int main() { return 0; }
