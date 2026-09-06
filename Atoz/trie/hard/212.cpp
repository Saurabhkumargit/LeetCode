// https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int m, n;

    void insert(const string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        char ch = board[r][c];

        if (ch == '#')
            return;

        TrieNode* next = node->child[ch - 'a'];

        if (!next)
            return;

        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        m = board.size();
        n = board[0].size();

        for (const string& word : words) {
            insert(word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};