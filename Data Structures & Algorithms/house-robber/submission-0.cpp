class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        if(n-i == 1)
            return dp[i] = nums[i];
        else if(n-i == 2)
            return dp[i] = max(nums[i], nums[i+1]);
        else{
            int m1 = nums[i] + helper(i+2, nums, dp);
            int m2 = nums[i+1] + helper(i+3, nums, dp);
            return dp[i] = max(m1,m2);
        }
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
