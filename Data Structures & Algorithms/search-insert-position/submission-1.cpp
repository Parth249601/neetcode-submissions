class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start =0, end = nums.size() -1;
        if(end == -1) return 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[start] > target)
                return start;
            else if(nums[end] < target)
                return end + 1;
            else if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid -1;
        }
        return -1;
    }
};