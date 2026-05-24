class Solution {
public:
    int helper(int start, vector<int>& prices, vector<int>& dp){
        //dp[i] represents the maximum profit that could be made from index i to n-1 array
        int n = prices.size();
        if(dp[start] != -1) return dp[start];
        if(n - start == 1) return dp[start] = 0;
        
        int max_profit = 0;
        for(int i = start + 1; i<n; i++){
            //sell on day i
            int currProfit = prices[i] - prices[start] + helper(i, prices, dp);
            max_profit = max(max_profit, currProfit);
        }
        return dp[start] = max(dp[start+1], max_profit);
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, -1);
        return helper(0, prices, dp);
    }
};