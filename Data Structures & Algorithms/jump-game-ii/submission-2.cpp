class Solution {
public:
    int helper(int start, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(start == n-1) return dp[start] = 0;
        if(start + nums[start] >= n-1) return dp[start] = 1;
        if(nums[start] == 0) return dp[start] = INT_MAX;
        if(dp[start] != -1) return dp[start];
        int minJumps = INT_MAX;
        for(int i = start + 1; i <= start + nums[start]; i++){
            int jump_from_next = helper(i, nums, dp);
            if(jump_from_next == INT_MAX) continue;
            minJumps = min(minJumps, 1 + jump_from_next);
        }
        return dp[start] = minJumps; 
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);

    }
};
