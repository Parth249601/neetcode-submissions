class Solution {
public:
    int helper(int start, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(start == n-1) return dp[start] = 1;
        if(start + nums[start] >= n-1) return dp[start] = 1;
        if(dp[start] != -1) return dp[start];
        for(int i = start + 1; i <= start + nums[start]; i++){
            if(helper(i, nums, dp)) return dp[start] = 1; 
        }
        return dp[start] = 0;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        vector<int> dp(n, -1);
        return helper(0, nums, dp) == 1;
    }
};
