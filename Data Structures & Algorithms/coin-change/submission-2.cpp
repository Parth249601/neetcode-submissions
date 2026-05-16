class Solution {
public:
    int helper(int n, vector<int>& coins, int amount, vector<vector<int>> & dp){
        //base case
        if(dp[n-1][amount] != -2) return dp[n-1][amount];
        if(amount == 0) return dp[n-1][amount] = 0;
        if(n == 1){
            if(amount% coins[n-1] == 0) return dp[n-1][amount] = (amount/coins[n-1]);
            else return dp[n-1][amount] = -1;
        }

        int choice1 = INT_MAX;
        // Prevent negative array indexing
        if(amount >= coins[n-1]){
            int res = helper(n, coins, amount - coins[n-1], dp);
            if(res != -1) choice1 = 1 + res; // Prevent adding 1 to an invalid (-1) state
        }

        int choice2 = helper(n-1, coins, amount, dp);
        if(choice2 == -1) choice2 = INT_MAX;

        int minCoins = min(choice1, choice2);
        
        if(minCoins == INT_MAX) return dp[n-1][amount] = -1;
        else return dp[n-1][amount] = minCoins;   
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-2));
        sort(coins.begin(), coins.end());
        return helper(coins.size(), coins, amount, dp);
    }
};
