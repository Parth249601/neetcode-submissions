class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        unordered_set<int> seen;
        int n = nums.size();
        for(int i=0; i < n; i++){
            if(seen.find(nums[i]) == seen.end()){
                nums[k] = nums[i];
                k++;
                seen.insert(nums[i]);
            }
        } 
        return k;
    }
};