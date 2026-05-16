class Solution {
public:
    int helper(int i,vector<int>& cost, vector<int>& dp){
        int n = cost.size();
        if(i>= n) return 0;
        if(dp[i] != - 1) return dp[i];
        if(n-i == 1 || n-i == 2)
            return dp[i] = cost[i];
        //at least 3 elements
        int m1 = cost[i] + helper(i+1, cost, dp);
        int m2 = cost[i] + helper(i+2, cost, dp);
        return dp[i] = min(m1,m2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        vector<int> dp(cost.size(), -1);
        int m1 = helper(0, cost, dp);
        int m2 = helper(1, cost, dp);
        return min(m1,m2);
    }
};
