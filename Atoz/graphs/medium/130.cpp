// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '#';

        vector<pair<int, int>> ds = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : ds) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    board[nx][ny] == 'O') {

                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Top and bottom borders
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                bfs(board, m - 1, j);
        }

        // Left and right borders
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                bfs(board, i, n - 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};