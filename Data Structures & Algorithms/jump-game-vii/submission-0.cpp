class Solution {
public:
    int helper(int start, int minJump, int maxJump, string& s, vector<int>& dp){
        int n = s.length();
        if(start == n-1) return dp[start] = s[start] == '0' ? 1 : 0;
        if(dp[start] != -1) return dp[start]; 
        bool ans = false;
        for(int i = start + minJump; i < n && i <= start + maxJump; i++){
            if(s[i] == '1') continue;
            ans = ans || helper(i, minJump, maxJump, s, dp);
        }
        return dp[start] = ans ? 1  : 0;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> dp(n ,-1);
        return helper(0, minJump, maxJump, s, dp) == 1;
    }
};