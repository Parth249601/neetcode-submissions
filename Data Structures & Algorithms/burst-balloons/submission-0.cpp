class Solution {
public:
    int helper(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int max_coins = 0;
        for(int i= left; i<=right; i++){
            //Choose nums[i] as the indestructible wall
            int ll = left, lr = i-1;
            int rl = i+1, rr = right;
            int num = nums[left-1]*nums[i]*nums[right+1] + helper(ll, lr, nums, dp) + helper(rl, rr, nums, dp);
            max_coins = max(max_coins, num);
        }
        return dp[left][right] = max_coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(1,n-2, nums, dp);
    }
};
