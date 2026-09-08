// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxArea = 0;
    int area = 0;
    int r, c;

    void dfs(vector<vector<int>>& grid, int r, int c, int& maxArea, int& area) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == 0)
            return;

        grid[r][c] = 0;
        area++;

        dfs(grid, r + 1, c, maxArea, area);
        dfs(grid, r - 1, c, maxArea, area);
        dfs(grid, r, c + 1, maxArea, area);
        dfs(grid, r, c - 1, maxArea, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (r = 0; r < m; r++) {
            for (c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    area = 0;
                    dfs(grid, r, c, maxArea, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};