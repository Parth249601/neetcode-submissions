class Solution {
public:
    int ways(int start, vector<int> & coins, int target,vector<vector<int>>& dp){
        int n = coins.size();
        if(start == n) return target == 0 ? 1 : 0;
        if(target < 0) return 0;
        if(dp[start][target] != -1) return dp[start][target];
        int ways1 = ways(start, coins, target - coins[start], dp);
        int ways2 = ways(start + 1, coins, target, dp);
        return dp[start][target] = ways1 + ways2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return ways(0, coins, amount, dp);
    }
};
