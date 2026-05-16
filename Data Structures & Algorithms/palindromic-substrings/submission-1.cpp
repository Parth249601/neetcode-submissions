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
    int helper(int i, const string& s, vector<int>& dp, vector<vector<int>>& palindromes){
        int n = s.length();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(n-i == 1){palindromes[i][i] = 1; return dp[i] = 1;}
        //check number of palindrome as i
        int num1 = 1;
        for(int j = i+1; j<n; j++){
            if(palindromes[i][j] != -1) 
                num1 += palindromes[i][j];
            else{
                if(check_palindrome(i,j,s)){
                    //since i, j are palindromes i+1, j-1 all are 
                    int tempi = i, tempj = j;
                    palindromes[tempi][tempj] = 1;
                    while(tempi + 1 <= tempj - 1){
                        palindromes[tempi + 1][tempj -1] = 1;
                        tempi++; tempj--;
                    }
                    num1++;
                }
            }
        }
        return dp[i] = num1 + helper(i+1, s, dp, palindromes);
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        vector<vector<int>> palindromes(n, vector<int>(n, -1));
        return helper(0, s, dp, palindromes);
    }
};
