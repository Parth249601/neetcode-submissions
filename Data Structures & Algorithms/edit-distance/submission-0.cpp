class Solution {
public:
    int helper(int i, int j, string& word1, string& word2,vector<vector<int>>& dp){
        if(i <0 || j < 0) return max(0, max(i+1, j+1));
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = helper(i-1,j-1, word1, word2, dp);
        else{
            int num1 = helper(i-1,j, word1, word2, dp);
            int num2 = helper(i,j-1, word1, word2, dp);
            int num3 = helper(i-1, j-1, word1, word2, dp);
            return dp[i][j] = 1 + min(num3, min(num1, num2));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1,n-1, word1, word2, dp);
    }
};
