class Solution {
public:
    bool helper(int start, vector<int>& nums, int sum, vector<vector<int>>& dp){

        int n = nums.size();
        if(start >= n) return false;
        if(dp[start][sum] != -1) return dp[start][sum] == 1;

        if(n - start == 1){
            if(nums[start] == sum)
                return dp[start][sum] = 1;
            else 
                return dp[start][sum] = 0;
        }

        bool var = helper(start + 1, nums, sum - nums[start], dp) || helper(start + 1, nums, sum, dp);
        if(var) dp[start][sum] = 1; else dp[start][sum] = 0;
        return var;
    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int i=0; i < nums.size(); i++)
            totalSum += nums[i];
        if(totalSum % 2 != 0) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(totalSum/2 + 1,-1));
        //try to find a subarray with sum totalSum/2; 
        return helper(0, nums, totalSum/2, dp);
        
    }
};
