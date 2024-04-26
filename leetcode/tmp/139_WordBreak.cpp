#include "utils.h"

struct TrieNode {
  std::unordered_map<char, TrieNode *> children;
  bool endOfWord;

  TrieNode() : endOfWord(false) {}
};

class Trie {
private:
  TrieNode *m_root;

private:
  void clear(TrieNode *node) {
    for (auto child : node->children) {
      clear(child.second);
    }
    delete node;
  }

public:
  Trie() { m_root = new TrieNode(); }
  ~Trie() { clear(m_root); }

  void insert(std::string word) {
    TrieNode *node = m_root;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        node->children[ch] = new TrieNode();
      }
      node = node->children[ch];
    }
    node->endOfWord = true;
  }

  bool search(std::string word) {
    TrieNode *node = m_root;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        return false;
      }
      node = node->children[ch];
    }
    return node->endOfWord;
  }

  bool startsWith(std::string prefix) {
    TrieNode *node = m_root;
    for (char ch : prefix) {
      if (node->children.find(ch) == node->children.end()) {
        return false;
      }
      node = node->children[ch];
    }
    return true;
  }
};

bool wordBreak2(const std::string &s, //Study this one
                const std::vector<std::string> &wordDict) {
  Trie trie;
  for (auto &word : wordDict) {
    trie.insert(word);
  }

  std::function<bool(int, int)> wordBreaker = [&](int left, int right) {
    if (left + right == s.length())
      return true;
    std::cout << "[" << left << "," << right << "]" << std::endl;
    LOG(s.substr(left, right));
    if (trie.startsWith(s.substr(left, right))) {
      if (!trie.search(s.substr(left, right))) {
        return wordBreaker(left, right + 1);
      } else {
        return wordBreaker(left + right, 0);
      }
    }
    return false;
  };
  return wordBreaker(0, 0);
};

bool wordBreak(const std::string &s, const std::vector<std::string> &wordDict) {
  std::unordered_set<std::string> wd(wordDict.begin(), wordDict.end());
  int n = s.length();
  std::vector<bool> dp(n + 1, false);
  dp[0] = true;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] && wd.count(s.substr(j, i - j))) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[n];
}

int main() {
  std::vector<std::string> wd = {"leet", "code"};
  std::string s = "applepenapple";

  LOG(wordBreak2(s, wd));

  return 0;
}
