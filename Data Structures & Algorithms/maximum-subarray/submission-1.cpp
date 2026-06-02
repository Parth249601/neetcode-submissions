class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i=0; i<n; i++){
            if(i== 0) dp[i] = nums[0];
            if(i>0) dp[i] = max(nums[i], dp[i-1] + nums[i]);
            max_sum = max(max_sum, dp[i]);

        }
        return max_sum;
    }
};
