class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //so the thought would be to set a sliding window of k, check if n < k
        int n = nums.size();
        int left = 0, right = k;
        unordered_set<int> seen;
       
        for(int i=0; i<n && i<= k; i++){
            if(seen.find(nums[i]) != seen.end()){
                cout << "Hi1" << endl;
                return true;
            }
            else
                seen.insert(nums[i]);
        }
        seen.erase(nums[left]);left++; right++;
        
        while(right < n){
            if(seen.find(nums[right]) != seen.end())
                return true;
            else
                seen.insert(nums[right]);
            seen.erase(nums[left]);
            left++; right++;
        }
        return false;
    }
};