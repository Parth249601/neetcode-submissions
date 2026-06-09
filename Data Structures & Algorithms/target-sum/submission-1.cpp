class Solution {
public:
    int total = 0;
    int helper(int start, vector<int>& nums, int target, vector<vector<int>>& dp){
        int n = nums.size();
        if(start >= n) return target == 0 ? 1 : 0;
        int idx = target + total;
        if (idx < 0 || idx > 2 * total) return 0; // unreachable, prune
        if(dp[start][idx] != -1) return dp[start][idx];

        int ways1 = helper(start + 1, nums, target - nums[start], dp);
        int ways2 = helper(start + 1, nums, target + nums[start], dp);
        return dp[start][idx] = ways1 + ways2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        for (int x : nums) total += x;
        if (abs(target) > total) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * total + 1, -1));
        return helper(0, nums, target, dp);
    }
};
