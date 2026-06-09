class Solution {
public:
    int mps(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = dp.size(), n = dp[0].size();
        if(r == m-1 && c == n-1) return dp[r][c] = grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        //Now I have two options, go right or down
        int right = INT_MAX, down = INT_MAX;
        int rr = r + 1, cc = c + 1;
        if(rr < m) right = mps(rr, c, grid, dp);
        if(cc < n) down = mps(r, cc, grid, dp);
        return dp[r][c] = grid[r][c] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return mps(0,0,grid,dp);
    }
};