// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                char num = board[i][j];
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i].count(num) ||
                    cols[j].count(num) ||
                    boxes[box].count(num))
                    return false;

                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};


// Alt Method
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[b][num])
                    return false;

                row[i][num] = col[j][num] = box[b][num] = true;
            }
        }
        return true;
    }
};


// Revision (1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                char c = board[i][j];
                int box = (i/3) * 3 + (j/3);

                if (rows[i].count(c) || cols[j].count(c) || boxes[box].count(c))
                    return false;
                
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
};


// Revision (2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[b][num])
                    return false;
                
                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }
        return true;
    }
};