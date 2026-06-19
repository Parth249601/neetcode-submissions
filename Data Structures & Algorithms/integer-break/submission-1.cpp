class Solution {
public:
    int helper(int start, vector<int>& nums, vector<vector<int>>& dp, int target){

    }
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); dp[0] = 0;
        for(int i = 2; i<=n; i++){
            int start = ceil((double)(i)/2);
            //cout << start << " " << endl;
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], j * max(dp[i-j], i-j));
            }
            //cout << "ans for " << i << " " << dp[i] << endl;
        }
        return dp[n];
    }
};