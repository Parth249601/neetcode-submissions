class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int>& dp){
        int n = nums.size();
        if(target < 0) return 0;
        if(target == 0) return dp[target] = 1;

        if(dp[target] != -1) return dp[target];
        //if target < smallest
        dp[target] = 0;
        for(int i = 0; i < nums.size(); i++)
            if(target - nums[i] >= 0) dp[target] += helper(nums, target -nums[i], dp);
        return dp[target];

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return helper(nums, target, dp);
    }
};