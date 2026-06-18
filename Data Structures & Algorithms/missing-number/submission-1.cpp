class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int bitwise = 0, n = nums.size();
        for(int i =0; i<=n; i++)
            bitwise ^= i;
        for(int i=0; i<n; i++)
            bitwise ^= nums[i];
        return bitwise;
    }
};
