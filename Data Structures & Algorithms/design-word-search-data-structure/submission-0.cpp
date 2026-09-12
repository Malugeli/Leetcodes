class WordDictionary {
private:
    struct TrieNode {
        std::array<TrieNode*, 26> children{};
        bool is_end = false;
    };

    TrieNode* root;

    bool dfs(const std::string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->is_end;
        }

        char c = word[index];

        if (c == '.') {
            for (TrieNode* child : node->children) {
                if (child != nullptr &&
                    dfs(word, index + 1, child)) {
                    return true;
                }
            }

            return false;
        }

        int childIndex = c - 'a';

        if (node->children[childIndex] == nullptr) {
            return false;
        }

        return dfs(
            word,
            index + 1,
            node->children[childIndex]
        );
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(std::string word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->is_end = true;
    }

    bool search(std::string word) {
        return dfs(word, 0, root);
    }
};