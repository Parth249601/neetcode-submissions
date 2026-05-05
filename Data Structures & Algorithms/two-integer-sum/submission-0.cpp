class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Key: The number, Value: Its index
        unordered_map<int, int> lookup_table;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];

            // 1. Check if the complement is already in the map
            auto it = lookup_table.find(complement);
            if (it != lookup_table.end()) {
                // If found, it->second is the index of the complement
                return {it->second, i};
            }

            // 2. If not found, add the current number and its index to the map
            lookup_table[nums[i]] = i;
        }
        
        return {}; // Return empty if no solution is found
    }
};