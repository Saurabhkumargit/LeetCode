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
