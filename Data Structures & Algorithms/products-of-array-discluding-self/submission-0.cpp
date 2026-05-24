class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), product = 1, count_zeros =0, product_without = 1;
        for(int i=0; i< n; i++){
            product *= nums[i];
            if(nums[i] != 0) product_without *= nums[i];
            if(nums[i] == 0) count_zeros++;
        }
        vector<int> ans(n, product);
        for(int i =0; i <n; i++){
            if(nums[i] != 0) ans[i] /= nums[i];
            else{
                if(count_zeros == 1) ans[i] = product_without;
                else ans[i] = 0;
            }
        }
        return ans;
    }
};
