class Solution {
public:
    bool check_palindrome(int start, int end, const string& s){
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++; end--;
        }
        return true;
    }
    int helper(int i, const string& s, vector<int>& dp){
        int n = s.length();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(n-i == 1) return dp[i] = 1;
        //check number of palindrome as i
        int num1 = 1;
        for(int j = i+1; j<n; j++)
            if(check_palindrome(i,j, s)) num1++;
        return dp[i] = num1 + helper(i+1, s, dp);
    
    }
    int countSubstrings(string s) {
        vector<int> dp(s.length(), -1);
        return helper(0, s, dp);
    }
};
