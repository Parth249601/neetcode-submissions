class Solution {
public:
    int helper(int i, const string& s, vector<int>& dp){
        int n = s.length();
        if(i>=n) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0;

        if(n-i == 1) return dp[i] = 1;

        if(s[i] -'0' >= 3 || (s[i] -'0' == 2 && s[i+1] -'0' >= 7)) return dp[i] = helper(i+1, s, dp);
        else return dp[i] = helper(i+1,s, dp) + helper(i+2, s, dp);        
        
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return helper(0, s, dp);
    }   
};
