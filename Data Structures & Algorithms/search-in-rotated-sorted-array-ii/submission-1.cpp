class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, n = nums.size();
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
                return true;
            if (nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue; // Skip the rest of the loop and recalculate mid
            }
            //Check if the left half of the array is sorted
            if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid])
                    end = mid -1;
                else
                    start = mid + 1;
            }

            else{
                //Right half of the array is sorted
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                //since right half is sorted, and if target < nums[mid] we must move left
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};