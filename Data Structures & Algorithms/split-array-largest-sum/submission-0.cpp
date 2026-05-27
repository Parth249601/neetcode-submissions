class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int maxSum, int maxElement){
        if(maxElement > maxSum) return false;
        int currSum = 0, subarrays = 1;
       
        for(int i = 0; i < nums.size(); i++){
            if(currSum + nums[i] > maxSum){ //we have reached the limit of this subarray start a new one
                subarrays++;
                currSum = nums[i];
            } 
            else currSum += nums[i];
        }
        return subarrays <= k; 
    }
    int splitArray(vector<int>& nums, int k) {
        int end = 0, maxElement = nums[0];
        for(int num : nums){
            end += num;
            maxElement = max(maxElement, num);
        }
        int start =0;
        //start is 0 min subarray sum and max is the total Sum of the array
        while(start < end){
            int mid = start + (end - start)/2;
            if(isPossible(nums, k , mid, maxElement))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};