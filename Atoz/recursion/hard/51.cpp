// https://leetcode.com/problems/n-queens/

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));

        // column, diagonal, anti-diagonal trackers
        vector<bool> col(n, false);
        vector<bool> diag(2 * n - 1, false);     // r - c + n - 1
        vector<bool> antiDiag(2 * n - 1, false); // r + c

        backtrack(0, n, board, col, diag, antiDiag, solutions);
        return solutions;
    }

    void backtrack(int row, int n, vector<string> &board,
                   vector<bool> &col,
                   vector<bool> &diag,
                   vector<bool> &antiDiag,
                   vector<vector<string>> &solutions)
    {
        if (row == n)
        {
            solutions.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            int d = row - c + n - 1;
            int ad = row + c;

            if (!col[c] && !diag[d] && !antiDiag[ad])
            {
                // place queen
                board[row][c] = 'Q';
                col[c] = diag[d] = antiDiag[ad] = true;

                // move to next row
                backtrack(row + 1, n, board, col, diag, antiDiag, solutions);

                // remove queen
                board[row][c] = '.';
                col[c] = diag[d] = antiDiag[ad] = false;
            }
        }
    }
};



// Revision (1)
class Solution {
public:

    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, n, board)) {

                board[row][col] = 'Q';

                solve(row + 1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, int n, vector<string>& board) {

        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);

        return ans;
    }
};