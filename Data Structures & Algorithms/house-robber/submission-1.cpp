class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        //Two options 
        int m1 = nums[i] + helper(i+2, nums, dp);
        int m2 = helper(i+1, nums, dp);
        
        return dp[i] = max(m1, m2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
