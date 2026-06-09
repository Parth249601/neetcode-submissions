class Solution {
public:
    int uP(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = dp.size(), n = dp[0].size();
        if(grid[r][c] == 1) return dp[r][c] = 0;
        if(r == m-1 && c == n-1) return grid[r][c] == 0 ? dp[r][c] = 1 : dp[r][c] = 0;
        if(dp[r][c] != -1) return dp[r][c];
        int right = 0, down = 0;
        int rr = r + 1, cc= c + 1;
        if(rr < m && grid[rr][c] != 1)
            right += uP(rr, c, grid, dp);
        if(cc < n && grid[r][cc] != 1)
            down += uP(r, cc, grid, dp);
        return dp[r][c] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uP(0, 0, obstacleGrid, dp);
    }
};