class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 1 || n == 2){
            return dp[n-1] = n;
        }
        if(dp[n-1] != -1) return dp[n-1];
        return dp[n-1] = (helper(n-1, dp) + helper(n-2, dp));

    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return helper(n,dp);
    }
};
