class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpmax(n);
        vector<int> dpmin(n);
        dpmax[0] = nums[0]; dpmin[0] = nums[0];
        for(int i=1; i<n; i++){
            dpmax[i] = max(nums[i], max(dpmax[i-1]* nums[i], dpmin[i-1]* nums[i]));
            dpmin[i] = min(nums[i], min(dpmax[i-1]* nums[i], dpmin[i-1]* nums[i]));
        }
        return *max_element(dpmax.begin(), dpmax.end());
    }
};
