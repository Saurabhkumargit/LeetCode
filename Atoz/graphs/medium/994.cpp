// https://leetcode.com/problems/rotting-oranges/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Initialize queue + count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool didRot = false;

            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                // 4 directions
                if (x > 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    q.emplace(x-1, y);
                    fresh--;
                    didRot = true;
                }
                if (x+1 < n && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    q.emplace(x+1, y);
                    fresh--;
                    didRot = true;
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    q.emplace(x, y-1);
                    fresh--;
                    didRot = true;
                }
                if (y+1 < m && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    q.emplace(x, y+1);
                    fresh--;
                    didRot = true;
                }
            }

            if (didRot) minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};