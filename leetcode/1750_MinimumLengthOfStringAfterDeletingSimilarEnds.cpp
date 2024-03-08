
#include <iostream>
#include <vector>

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
    int t;  // Minimum degree
    bool leaf; // Is true when node is leaf

    BTreeNode(int _t, bool _leaf);

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
};

class BTree {
private:
    BTreeNode* root;
    int t;  // Minimum degree

public:
    BTree(int _t): root(nullptr), t(_t) {}

    void insert(int key);
};

BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    keys.reserve(2*t-1);
    children.reserve(2*t);
}

void BTreeNode::insertNonFull(int key) {
    // Implementation for inserting a key into a non-full node
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    // Implementation for splitting the child y of this node
}

void BTree::insert(int key) {
    // Implementation for inserting a new key in the B-Tree
}

int main() {
    BTree t(3); // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    // Insert more keys as needed

    return 0;
}
