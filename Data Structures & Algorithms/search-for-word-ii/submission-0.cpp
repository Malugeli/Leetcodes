class Solution {
  struct TrieNode {
    std::array<TrieNode *, 26> children{};
    std::string word;
  };

  std::vector<std::string> result;

  void dfs(std::vector<std::vector<char>> &board, int r, int c, TrieNode *parent) {
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
    char letter = board[r][c];
    if (letter == '#') return;

    TrieNode *node = parent->children[letter - 'a'];
    if (!node) return;

    if (!node->word.empty()) {
      result.push_back(node->word);
      node->word.clear();
    }

    board[r][c] = '#';
    dfs(board, r - 1, c, node);
    dfs(board, r + 1, c, node);
    dfs(board, r, c - 1, node);
    dfs(board, r, c + 1, node);
    board[r][c] = letter;
  }

public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {
    TrieNode *root = new TrieNode;
    for (const std::string &w : words) {
      TrieNode *cur = root;
      for (char ch : w) {
        int i = ch - 'a';
        if (!cur->children[i]) cur->children[i] = new TrieNode;
        cur = cur->children[i];
      }
      cur->word = w;
    }

    for (int r = 0; r < (int)board.size(); ++r)
      for (int c = 0; c < (int)board[0].size(); ++c)
        dfs(board, r, c, root);
    return result;
  }
};