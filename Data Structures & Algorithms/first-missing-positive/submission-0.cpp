class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i < nums.size(); i++){
            if(nums[i] >= 1 && nums[i] <= n){
                bool isSame = (nums[i] == nums[nums[i] - 1]);
                if(!isSame){
                    swap(nums[i], nums[(nums[i] - 1)]);
                    i--;
                } 
                
            }
        }
        int target = 1;
        for(int i=0; i <n; i++){
            if(nums[i] == target) target++;
            else break;
        }
        return target;
    }
};