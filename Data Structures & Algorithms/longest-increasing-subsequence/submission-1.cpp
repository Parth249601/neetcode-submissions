class Solution {
public:
    int helper(int start, int prevIndex ,vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(start >= n || n == 0) return 0;
        if(dp[start][prevIndex + 1] != -1) return dp[start][prevIndex + 1];

        // Choice 1: Skip the current element
        int skip = helper(start + 1, prevIndex, nums, dp);

        // Choice 2: Take the current element (ONLY if it's strictly greater than the previous)
        int take = 0;
        if(prevIndex == -1 || nums[start] > nums[prevIndex]){
            take = 1 + helper(start + 1, start, nums, dp); // Pass 'start' as the new prevIndex
        }

        return dp[start][prevIndex + 1] = max(skip, take);



    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);

        // for(int i= n-1; i>=0; i--){
        //     if(i == n-1){dp[i] = 1;continue;}
        //     vector<int> temparr;
        //     for(int j = i+1; j < n; j++){
        //         if(nums[j] > nums[i]) 
        //             temparr.push_back(nums[j]);
        //     }
        //     dp[i] = max(dp[i+1], 1 + lengthOfLIS(temparr));

        // }
        // return dp[0];
    }
};
