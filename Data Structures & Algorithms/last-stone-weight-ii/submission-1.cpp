class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for(int num : stones)
            totalSum += num;
        int n = stones.size();
        int capacity = totalSum / 2;
        // dp[i][j] = can we make sum j using first i stones?
        vector<vector<bool>> dp(n+1, vector<bool>(capacity+1, false));

        for(int i=0; i<=n; i++) dp[i][0] = true;

        for(int i=1; i<=n; i++){
            int w = stones[i-1];
            for(int j = 1; j<= capacity; j++){
                dp[i][j] = dp[i-1][j]; //leave stone[i]
                if(j >= w)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-w]; //take stone i
            }
        }


        for(int j = capacity; j>= 0; j--)
            if(dp[n][j]) return totalSum - 2 * j;

        return 0;
    }
};