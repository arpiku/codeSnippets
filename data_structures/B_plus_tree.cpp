
#include <iostream>
#include <vector>

class BPTreeNode {
public:
    bool isLeaf;
    std::vector<int> keys;
    std::vector<BPTreeNode*> children; // Used only in non-leaf nodes
    std::vector<int> values; // Used only in leaf nodes

    BPTreeNode(bool leaf): isLeaf(leaf) {}

    void insertNonFull(int key, int value);
    void splitChild(int i, BPTreeNode* y);
};

class BPlusTree {
private:
    BPTreeNode* root;
    int degree; // Minimum degree (defines the range for the number of keys)

public:
    BPlusTree(int _degree): root(nullptr), degree(_degree) {}

    // Function to insert a new key
    void insert(int key, int value);
};

void BPTreeNode::insertNonFull(int key, int value) {
    // Implementation for inserting a key into a non-full node
}

void BPTreeNode::splitChild(int i, BPTreeNode* y) {
    // Implementation for splitting the child y of this node. Note that y must be full when this function is called
}

void BPlusTree::insert(int key, int value) {
    // Implementation for inserting a new key in the B+ Tree
}

int main() {
    BPlusTree tree(3); // A B+ Tree with a minimum degree of 3
    tree.insert(10, 100);
    tree.insert(20, 200);
    // Insert more keys and values as needed

    return 0;
}
