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
