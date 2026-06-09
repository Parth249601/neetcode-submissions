class Solution {
public:
    int uP(int r, int c, vector<vector<int>>& dp){
        int m = dp.size(), n = dp[0].size();
        //r => r + 1, c => c + 1
        if(r == m-1 && c == n-1) return dp[r][c] = 1;
        if(dp[r][c] != -1) return dp[r][c];

        int rr = r + 1, cc = c + 1;
        int right =0,  down = 0;
        if(rr < m) {
            right += uP(rr, c, dp);
        }
        if(cc < n) {
            down += uP(r, cc, dp); 
        }
        return dp[r][c] = right + down;
    }
    int uniquePaths(int m, int n) {
        //move down or right is the key question is screaming DP
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uP(0,0,dp);
    }
};
