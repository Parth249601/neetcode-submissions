class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> frequency;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(frequency.find(nums[i]) == frequency.end())
                frequency[nums[i]] = 1;
            else
                frequency[nums[i]]++;
        }

        for(auto& [key, value] : frequency){
            if(value > (nums.size())/3)
                ans.push_back(key);
        }
        return ans;
    }
};