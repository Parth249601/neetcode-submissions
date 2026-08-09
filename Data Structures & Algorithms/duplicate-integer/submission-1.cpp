class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num: nums)
            mp[num]++;
        for(auto& [num,f] : mp){
            if(f>1) return true;
        }
        return false;
    }
};