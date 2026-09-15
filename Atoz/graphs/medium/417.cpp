// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> qp, qa;

        // Pacific: top row + left column
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            qp.push({i, 0});
        }

        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            qp.push({0, j});
        }

        // Atlantic: bottom row + right column
        for (int i = 0; i < m; i++) {
            atlantic[i][n - 1] = true;
            qa.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            atlantic[m - 1][j] = true;
            qa.push({m - 1, j});
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        auto bfs = [&](queue<pair<int, int>>& q,
                       vector<vector<bool>>& ocean) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (ocean[nr][nc])
                        continue;

                    if (heights[nr][nc] < heights[r][c])
                        continue;

                    ocean[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        };

        bfs(qp, pacific);
        bfs(qa, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};