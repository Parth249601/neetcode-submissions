class Solution {
public:
    //standard minimax problem
    int margin(int start, int end, vector<int>& piles, vector<vector<int>>& dp){
        int n =  piles.size();
        if(start == end && end <= n-1) return dp[start][end] = piles[start];
        if(dp[start][end] != 25001) return dp[start][end];

        int way1 = piles[start] - margin(start + 1, end, piles, dp);
        int way2 = piles[end] - margin(start, end-1, piles, dp);

        return dp[start][end] = max(way1, way2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 25001));
        return margin(0,0, piles, dp) >= 0;
    }
};