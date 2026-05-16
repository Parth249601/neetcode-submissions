class Solution {
public:
    bool helper(int i, string s, unordered_map<string, bool>& dict, vector<int>& dp){
        int n = s.length();
        //if(i >= n) return true; //we have found what we needed
        if(dp[i] != -1) return dp[i] == 1;
        string temp;
        for(int j=i; j<s.length(); j++){
            temp += s[j];
            if(dict.find(temp) != dict.end()){
                if(j + 1 == n){dp[i] = 1; return true;}
                if(helper(j+1, s, dict, dp)){dp[i] = 1; return true;}
            }
        }
        dp[i] = 0; return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(int i=0; i<wordDict.size(); i++)
            dict[wordDict[i]] = true;
        vector<int> dp(s.length(), -1);
        return helper(0, s, dict, dp);
    }
};
