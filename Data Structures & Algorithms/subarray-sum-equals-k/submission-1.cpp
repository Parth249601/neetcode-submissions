class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> sum(n, vector<int> (n, INT_MIN));
        
        int count = 0;
        for(int i=0; i<n; i++){
            sum[i][i] = nums[i];
            if(nums[i] == k) count ++;
        }
        

        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(sum[i][j] != INT_MIN && sum[i][j] == k) count++;
                else if(sum[i][j] != INT_MIN && sum[i][j] != k) continue;
                sum[i][j] = sum[i][j-1] + nums[j];
                if(sum[i][j] == k) count++;
            }
        }
        return count;
    }
};