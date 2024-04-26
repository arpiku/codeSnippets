#include "utils.h"

TreeNode *buildTree(vecInt preorder, vecInt inorder) {

  if (inorder.empty()) {
    return nullptr;
  }

  TreeNode *parent = new TreeNode(preorder.at(0));

  if (inorder.size() == 1) {
    return parent;
  }

  auto parentItr = std::find(inorder.begin(), inorder.end(), parent->val);

  vecInt leftSideInorder(inorder.begin(), parentItr);
  vecInt rightSideInorder(parentItr + 1, inorder.end());

  vecInt preorderLeft(preorder.begin() + 1,
                      preorder.begin() + leftSideInorder.size() + 1);
  vecInt preorderRight(preorder.begin() + leftSideInorder.size() + 1,
                       preorder.end());

  printVec(leftSideInorder);
  printVec(rightSideInorder);
  printVec(preorderLeft);
  printVec(preorderRight);

  parent->left = buildTree(preorderLeft, leftSideInorder);
  parent->right = buildTree(preorderRight, rightSideInorder);
  return parent;
}

TreeNode *buildTreeHelper(const std::vector<int> &preorder,
                          const std::vector<int> &inorder, int preorderStart,
                          int preorderEnd, int inorderStart, int inorderEnd,
                          std::unordered_map<int, int> &inorderIndexMap) {
  if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
    return nullptr;
  }

  TreeNode *parent = new TreeNode(preorder[preorderStart]);
  int parentIndex = inorderIndexMap[parent->val];
  int leftSubtreeSize = parentIndex - inorderStart;

  parent->left = buildTreeHelper(preorder, inorder, preorderStart + 1,
                                 preorderStart + leftSubtreeSize, inorderStart,
                                 parentIndex - 1, inorderIndexMap);
  parent->right = buildTreeHelper(
      preorder, inorder, preorderStart + leftSubtreeSize + 1, preorderEnd,
      parentIndex + 1, inorderEnd, inorderIndexMap);

  return parent;
}

TreeNode *buildTreeFast(const std::vector<int> &preorder,
                        const std::vector<int> &inorder) {
  if (inorder.empty() || preorder.empty() ||
      inorder.size() != preorder.size()) {
    return nullptr;
  }

  std::unordered_map<int, int> inorderIndexMap; // Hashmap for O(1) lookup
  for (int i = 0; i < inorder.size(); ++i) {
    inorderIndexMap[inorder[i]] =
        i; // Store indices of elements in inorder array
  }

  return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1, inorderIndexMap);
}

int main() {
  vecInt in = {101, 10, 102, 9, 55, 11, 3, 21, 18, 15, 20, 7};
  vecInt pre = {3, 9, 10, 101, 102, 11, 55, 20, 15, 18, 21, 7};
  vecInt in2 = {-1};
  vecInt pre2 = {-1};
  TreeNode *root = buildTree(pre2, in2);
  printTreeGUI(root);
  delete root;
  return 0;
}
