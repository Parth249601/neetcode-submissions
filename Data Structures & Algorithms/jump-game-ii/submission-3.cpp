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
        int jumps = 0; int n = nums.size();
        int curr_max_reach = 0;
        int curr_level_end = 0;

        for(int i=0; i<n-1; i++){
            curr_max_reach = max(curr_max_reach, i + nums[i]);

            if(i == curr_level_end){
                jumps++;
                curr_level_end = curr_max_reach;
                //break early
                if (curr_level_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};
