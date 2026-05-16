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
    string lps(int start, int end, const string& s, vector<string>& dp){
        int n = end - start + 1;
        if(start > end) return "";
        if(dp[start] != "") return dp[start];
        if(n == 1) return dp[start] = s.substr(start, 1);
        else if(n == 2){
            if(s[start] == s[end]) return dp[start] = s.substr(start, 2);
            else return dp[start] = s.substr(start,1);
        }
        else{
            if(check_palindrome(start, end, s)) return dp[start] = s.substr(start, n);
            string ans1 = lps(start+1, end, s, dp);
            string ans2 = lps(start, end-1, s, dp);  
            if(ans1.length() >= ans2.length()) return dp[start] = ans1;
            else return dp[start] = ans2;
        }
    }
    string longestPalindrome(string s) {
        vector<string> dp(s.length(), "");
        return lps(0, s.length() - 1, s, dp);
    }
};
