class WordDictionary {
private:
  struct TrieNode {
    std::array<TrieNode *, 26> alphabet;
    bool is_end = false;
  };
  TrieNode *root;

  bool dfs(const std::string &word, size_t index, TrieNode *node) {
    if (index == word.size()) {
      return node->is_end;
    }

    char c = word[index];

    if (c == '.') {
      for (TrieNode *child : node->alphabet) {
        if (child != nullptr && dfs(word, index + 1, child)) {
          return true;
        }
      }

      return false;
    }

    size_t childIndex = static_cast<size_t>(c - 'a');

    if (node->alphabet[childIndex] == nullptr) {
      return false;
    }

    return dfs(word, index + 1, node->alphabet[childIndex]);
  }

public:
  WordDictionary() { root = new TrieNode(); }

  void addWord(std::string word) {
    TrieNode *current = root;

    for (auto c : word) {
      size_t index = static_cast<size_t>(c - 'a');
      if (!current->alphabet[index]) {
        current->alphabet[index] = new TrieNode();
      }
      current = current->alphabet[index];
    }
    current->is_end = true;
  }

  bool search(std::string word) {
    return dfs(word, 0, root);
  }
};
