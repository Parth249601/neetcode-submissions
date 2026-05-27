class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1, n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid != 0 && mid != n-1){
                if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1] && nums[mid] > nums[0])
                    start = mid + 1;
                else if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                    return nums[mid + 1];
                else if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])
                    return nums[mid];
                else
                    end = mid -1;    
            }
            else{
                return nums[end] > nums[start] ? nums[start] : nums[end];
            }
        }
        return -1;
    }
};
