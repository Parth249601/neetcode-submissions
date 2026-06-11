class Solution {
public:
    bool helper(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        int k = i + j;
        if(k == s3.length()) return true;

        if(dp[i][j] != -1) return dp[i][j] == 1;

        bool ans = false;
        if(i < s1.length() && s1[i] == s3[k]){
            ans = ans || helper(i+1,j, s1,s2,s3,dp);
        }
        if(!ans && j<s2.length() && s2[j] == s3[k]){
            ans = ans || helper(i, j+1,s1,s2,s3,dp);
        }

        return dp[i][j] = ans ? 1 : 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Immediate failure: length mismatch
        if (m + n != s3.length()) return false;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0,0,s1,s2,s3,dp) == 1;
    }
};
