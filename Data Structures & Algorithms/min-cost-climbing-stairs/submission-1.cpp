class Solution {
public:
    int helper(int i,vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        //at ith index i have  a decision to make
        int cost1 = cost[i] + helper(i+1, cost, dp);
        int cost2 = cost[i] + helper(i+2, cost, dp);

        return dp[i] = min(cost1, cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));

    }
};
