class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> dict;
        int n = nums.size();
        for(int i=0; i< n; i++){
            if(dict.find(nums[i]) == dict.end())
                dict[nums[i]] = 1;
            else
                dict[nums[i]]++;
        }

        for(auto& [key,value] : dict){
            cout << "Number " << key << " Value " << value << endl;
            if(value > n/2)
                return key;
            
        }
        return -1;

    }
};