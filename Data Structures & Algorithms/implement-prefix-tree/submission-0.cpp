class PrefixTree {
private:
  struct TrieNode {
    std::array<TrieNode *, 26> node{};
    bool is_end = false;
  };
  TrieNode* root;

public:
  PrefixTree() {
    root = new TrieNode();
  };

  void insert(std::string word) {
    auto current = root;
    for(auto c : word){
        int index = c - 'a';
       if(!current->node[index]){
        current->node[index] = new TrieNode();
       }
       current = current->node[index];
    }
    current->is_end = true;
  }

  bool search(std::string word) {
    auto current = root;
    for(auto c : word){
      int index = c - 'a';
      if (!current->node[index]) {
        return false;
      }
      current = current->node[index];
    }

    return current->is_end;
  }

  bool startsWith(std::string prefix) {
    auto current = root;
    for(auto c : prefix){
      int index = c - 'a';
      if (!current->node[index]) {
        return false;
      }
      current = current->node[index];
    }
    return true;
  }
};