// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        if (r<0 || c < 0 || r >=m || r>=n || image[r][c] != oldColor)
        return;

        image[r][c] = newColor;

        dfs(image, r +1, c, oldColor, newColor);
        dfs(image, r -1, c, oldColor, newColor);
        dfs(image, r , c + 1, oldColor, newColor);
        dfs(image, r , c - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        int newColor = color;

        if(oldColor == newColor) return image;

        dfs(image, sr,sc, oldColor, color);
        return image;
    }
};