#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    // Each TrieNode contains a map to child nodes and a boolean indicating end of word
    std::unordered_map<char, TrieNode*> children;
    bool endOfWord;

    // Constructor initializes endOfWord to false
    TrieNode() : endOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->endOfWord = true;
    }

    // Search if the word is in the trie
    bool search(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->endOfWord;
    }

    // Check if there is any word in the trie that starts with the given prefix
    bool startsWith(std::string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    // Destructor to clean up memory
    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode* node) {
        for (auto child : node->children) {
            clear(child.second);
        }
        delete node;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    std::cout << "Contains 'hello': " << trie.search("hello") << std::endl;
    std::cout << "Contains 'hell': " << trie.search("hell") << std::endl;
    std::cout << "Has prefix 'hell': " << trie.startsWith("hell") << std::endl;

    return 0;
}
