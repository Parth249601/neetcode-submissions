class Solution {
public:
    int helper(int i, int j, string& s1, string&s2, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return 1 + helper(i-1,j-1, s1, s2, dp);
        else{
            int num1 = helper(i-1,j,s1,s2,dp);
            int num2 = helper(i,j-1,s1,s2,dp);
            return dp[i][j] = max(num1,num2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length(); 
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m-1,n-1, text1, text2, dp);   

    }
};
