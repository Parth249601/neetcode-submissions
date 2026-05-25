class Solution {
public:
    int helper(vector<int>& prices, int left, int right, vector<vector<int>>& dp){
        int n = prices.size();
        if(left >= n) return 0;
        if(left == right) return dp[left][right] = 0;

        if(dp[left][right] != -1) return dp[left][right];

        if(right - left == 1){
            return dp[left][right] = prices[right] - prices[left] >= 0 ? prices[right] - prices[left] : 0;
        }

        int num1 = helper(prices, left+1, right, dp);
        int num2 = helper(prices, left, right- 1, dp);
        int num3 = prices[right] - prices[left];
        return dp[left][right] = max(num3, max(num1, num2));
        

    }
    int maxProfit(vector<int>& prices) {
        //if h(x) < h(y); x++ to see if we can locate even lower h(z) < h(x), but using similar logic i could do y-- 

        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(prices, 0, n-1, dp);

    }
};
