class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        for(int i = left; i<= right; i++)
            ans &= i;
        return ans;
    }
};