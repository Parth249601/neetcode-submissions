class Solution {
public:
    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,1,-1};
    int helper(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 1;
        if(dp[r][c] != -1) return dp[r][c];
        for(int k =0; k< 4; k++){
            int rr = r + dr[k];
            int cc = c + dc[k];
            if(rr >=0 && rr<m && cc>=0 && cc<n && matrix[rr][cc] > matrix[r][c]){
                int score = 1 + helper(rr,cc,matrix,dp);
                maxLen = max(maxLen, score);
            }
        }
        return dp[r][c] = maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen = 1;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                int ans = helper(i,j, matrix, dp);
                if(ans > maxLen) maxLen = ans;
            }
        }   
        return maxLen;
    }
};
