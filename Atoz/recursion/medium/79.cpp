// https://leetcode.com/problems/word-search/

class Solution
{
public:
    int rows, cols;

    bool dfs(vector<vector<char>> &board, string &word, int i, int r, int c)
    {
        if (i == word.size())
            return true; // Found entire word
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;
        if (board[r][c] != word[i])
            return false; // Char mismatch

        char temp = board[r][c];
        board[r][c] = '#'; // Mark visited

        // Explore all four directions
        bool found = dfs(board, word, i + 1, r + 1, c) ||
                     dfs(board, word, i + 1, r - 1, c) ||
                     dfs(board, word, i + 1, r, c + 1) ||
                     dfs(board, word, i + 1, r, c - 1);

        board[r][c] = temp; // Restore

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (dfs(board, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }
};


// Revision (1)
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, string& ans,
               int i, int j) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        if (board[i][j] != word[ans.length()]) {
            return false;
        }

        ans.push_back(board[i][j]);

        if (ans == word) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        if (solve(board, word, ans, i + 1, j) ||
            solve(board, word, ans, i, j + 1) ||
            solve(board, word, ans, i - 1, j) ||
            solve(board, word, ans, i, j - 1)) {
            return true;
        }

        board[i][j] = temp;
        ans.pop_back();

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        string ans = "";

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    if (solve(board, word, ans, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
