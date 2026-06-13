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
        if (s[n-1] == '1') return false;

        vector<int> dp(n, 0);
        dp[0] = 1;
        int prefix = 0;

        for(int i = minJump; i <n; i++){
            prefix += dp[i - minJump];
            if (i - maxJump - 1 >= 0)
                prefix -= dp[i - maxJump - 1];
            
            if (s[i] == '0' && prefix > 0)
                dp[i] = 1;
        }
        return dp[n-1] == 1;
    }
};