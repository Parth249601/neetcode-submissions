class Solution {
public:
    int check(vector<int>& nums, int target, int start){
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;

    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i < n-1; i++){
            int rem = target - nums[i];
            int a = check(nums, rem, i+1);
            if(a != -1) return {i+1, a+1}; 
        }
        return {0,0};
    }
};
