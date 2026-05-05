class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency_table;
        for(int i=0; i < nums.size(); i++){
            if(frequency_table.find(nums[i]) != frequency_table.end())
                frequency_table[nums[i]]++;
            else
                frequency_table[nums[i]] = 1;

        }

        vector<pair<int,int>> vec(frequency_table.begin(), frequency_table.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Descending order
        });

        vector<int> ans;
        for(int i=0; i <k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
            
    }
};
