class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> lookup_table;
        //stores the int and whether it has appeared before or not 
        for(int i=0; i < n; i++){
            //check if nums[i] is in the unordered_map
            if(lookup_table.find(nums[i]) != lookup_table.end())
                return true;
            else
                lookup_table[nums[i]] = true;
        }
        return false;
    }
};