class Solution {
public:
    int sum_squares(int n){
        int ans = 0;
        while(n){
            ans += (n%10) * (n%10);
            n /= 10;
        }
        return ans;
    }
    bool helper(int n, unordered_map<int,bool>& seen){
        int sum = sum_squares(n);
        if(sum == 1) return true;
        if(seen[sum]) return false;
        seen[sum] = true;
        return helper(sum, seen);

    }
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        return helper(n, seen);
    }
};
