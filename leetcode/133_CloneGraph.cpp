/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::unordered_map<Node*, Node*> visited;

Node* cloneGraph(Node* node) {
    if (!node) {
        return nullptr; // Return nullptr for an empty graph.
    }

    // If the node has already been cloned, return its clone.
    if (visited.find(node) != visited.end()) {
        return visited[node];
    }

    // Create a clone of the current node.
    Node* cloneNode = new Node(node->val);

    // Mark the node as visited and store its clone.
    visited[node] = cloneNode;

    // Recursively clone all neighbors of the current node.
    for (Node* neighbor : node->neighbors) {
        cloneNode->neighbors.push_back(cloneGraph(neighbor));
    }

    return cloneNode;
}
};
