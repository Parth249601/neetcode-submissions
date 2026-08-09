class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Key: The number, Value: Its index
        unordered_map<int, int> lookup_table;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            auto it = lookup_table.find(complement);

            if(it != lookup_table.end()){
                return {it->second, i};
            }
            lookup_table[nums[i]] = i;
        }
        
        return {}; // Return empty if no solution is found
    }
};