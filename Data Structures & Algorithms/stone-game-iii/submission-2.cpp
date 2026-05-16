class Solution {
public:
    int helper(int start, vector<int>& stoneValue, vector<int>& dp) {
        int n = stoneValue.size();
        if (start >= n) return 0;
        
        if (dp[start] != -1e9) return dp[start]; // Use a very small number for init
        
        int max_diff = -1e9;
        int current_take = 0;
    
        for (int i = 0; i < 3; i++) {
            if (start + i < n) {
                current_take += stoneValue[start + i];
                // Difference = (What I take now) - (What my opponent will take from the rest)
                int diff = current_take - helper(start + i + 1, stoneValue, dp);
                max_diff = max(max_diff, diff);
            }
        }
        
        return dp[start] = max_diff;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // Initialize with a number smaller than any possible score
        vector<int> dp(n, -1e9); 
        
        // Alice goes first. helper(0) returns Alice's score minus Bob's score.
        int alice_net_score = helper(0, stoneValue, dp);
        
        if (alice_net_score > 0) return "Alice";
        if (alice_net_score < 0) return "Bob";
        return "Tie";
    }
};