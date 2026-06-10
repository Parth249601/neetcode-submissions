class Solution {
public:
    //state can be a particular start point and x value
    int helper(int start, int x,vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffixSum){
        int n = piles.size();
        if(start >=n) return 0;
        if(start == n-1) return dp[start][x] = piles[start];
        if(dp[start][x] != -1) return dp[start][x];
        int maxStones = 0;
        for(int i = start; i < start + x && i < n; i++){
            if(max(x, 2*(i - start + 1)) < n){
                int bob = helper(i+1, max(x, 2 * (i - start + 1)), piles,dp, suffixSum);  //I have claimed i - start + 1 piles
                maxStones = max(maxStones, suffixSum[start] - bob);
            }
            else{
                int bob = helper(i+1, n, piles,dp, suffixSum);  //I have claimed i - start + 1 piles
                maxStones = max(maxStones, suffixSum[start] - bob);
            }
        }
        return dp[start][x] = maxStones;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 1) return piles[0];
        int totalSum = 0;
        for(int num : piles)
            totalSum += num;
        vector<int> suffixSum(n);
        suffixSum[0] = totalSum;
        for(int i=0; i<n; i++)
            if(i > 0) suffixSum[i] = suffixSum[i-1] - piles[i-1];
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0, 2, piles, dp, suffixSum);
    }
};