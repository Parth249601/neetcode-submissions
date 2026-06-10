class Solution {
public:
    int helper(int start, vector<int>& prices, bool canBuy, vector<vector<int>>& dp){
        //canBuy = 1 -> you can buy, p.second = price of the last element
        int n = prices.size(); if(start >= n) return 0;
        
        if(dp[(int)canBuy][start] != -1) return dp[(int)canBuy][start];

        int currEle = prices[start];
        if(canBuy){
            int profit1 = -prices[start] + helper(start+1, prices, false, dp); //bought today
            int profit2 = helper(start+1, prices, true, dp); //continue;
            return dp[(int)canBuy][start] = max(profit1, profit2);
        }
        else{
            int profit1 = prices[start] + helper(start + 2, prices, true, dp); //sell today
            int profit2 = helper(start + 1, prices, false, dp); //don't sell today
            return dp[(int)canBuy][start] = max(profit1, profit2);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), -1));
        return helper(0, prices, true, dp);
    }
};
