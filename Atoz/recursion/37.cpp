// https://leetcode.com/problems/sudoku-solver/

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {

                if (board[r][c] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, r, c, ch))
                        {
                            board[r][c] = ch;

                            if (solve(board))
                                return true;

                            board[r][c] = '.';
                        }
                    }
                    return false; // no valid number works
                }
            }
        }
        return true; // puzzle completed
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] == ch)
                return false;
            // column check
            if (board[i][col] == ch)
                return false;
            // 3×3 box check
            int br = 3 * (row / 3) + i / 3;
            int bc = 3 * (col / 3) + i % 3;
            if (board[br][bc] == ch)
                return false;
        }
        return true;
    }
};
