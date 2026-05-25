class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int currSum = 0;
        int minLen = INT_MAX;
        unordered_set<int> seen_indices;
        while(left <= right && right < n){
            if(seen_indices.find(right)  == seen_indices.end()){
                seen_indices.insert(right);
                currSum += nums[right];
            }
            if(currSum >= target){
                minLen = min(minLen, right -left +1);
                currSum -= nums[left]; seen_indices.erase(left);
                left++; //shrink the window 
            }
            else 
                right++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};