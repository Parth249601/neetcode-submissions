class Solution {
public:
    int helper(int i,int n ,vector<int>& nums, vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        if(n-i == 1)
            return dp[i] = nums[i];
        else if(n-i == 2)
            return dp[i] = max(nums[i], nums[n-1]);
        else{
            int m1 = nums[i] + helper(i+2, n,nums, dp);
            int m2 = nums[i+1] + helper(i+3, n,nums, dp);
            return dp[i] = max(m1,m2);
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(n, -1);
        int m1 = helper(0,n-1 ,nums, dp);
        vector<int> dp1(n,-1);
        int m2 = helper(1, n, nums,dp1);
        return max(m1,m2);
    }
};
