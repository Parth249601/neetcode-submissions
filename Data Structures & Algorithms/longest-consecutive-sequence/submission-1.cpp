class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); unordered_set<int> available;
        for(int i=0; i< n; i++)
            available.insert(nums[i]);
        
        int lcs = 0;
        for(int i=0; i < n; i++){
            int curr = nums[i];
            int lcs_i = 1;
            for(int j = 1; j <n; j++){
                if(available.find(curr + j) != available.end()) lcs_i ++;
                else break;
            }
            lcs = max(lcs, lcs_i);
        }
        return lcs;

    }
};
