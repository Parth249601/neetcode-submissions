class Solution {
public:
    bool check(int n){
        int start = 1, end = n;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid * mid == n)
                return true;
            else if(mid*mid > n)
                end = mid - 1;
            else
                start = mid +1;
        }
        return false;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        vector<int> perfSqrs;
        for(int i= 1; i <= n; i++){
            if(check(i)){perfSqrs.push_back(i); dp[i] = 1; continue;}
            for(int j = perfSqrs.size() -1 ; j>= 0; j--)
                dp[i] = min(dp[i], 1 + dp[i - perfSqrs[j]]);
        }
        return dp[n];
    }
};