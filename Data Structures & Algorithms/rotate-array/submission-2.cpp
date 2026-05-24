class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0 || k == n) return;
        if(k > n) k = k%n;
        k = n -k;
        vector<int> v1, v2;
        for(int i=0; i<n; i++){
            if(i >= k) v2.push_back(nums[i]);
            else v1.push_back(nums[i]);
        }
        v2.insert(v2.end(), v1.begin(), v1.end());
        nums = v2;
    }
};