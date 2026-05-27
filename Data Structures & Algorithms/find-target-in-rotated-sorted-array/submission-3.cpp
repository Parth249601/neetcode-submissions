class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, n = nums.size();
        if(nums[0] < nums[n-1]){
            while(start <= end){
                int mid = start+ (end-start)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] > target)
                    end = mid -1;
                else 
                    start = mid +1;
            }
            return -1;
        }
        while(start <= end){
            int mid = start + (end -start)/2;
            if(mid != 0 && mid != n-1){
                if(nums[mid] == target)
                        return mid;
                if(target >= nums[0]){
                    cout << "Start " << start << " Mid " << mid << " End " << end << endl;
                    if(nums[mid] > target)
                        end = mid -1;
                    else if(nums[mid] < target && nums[mid] > nums[0])
                        start = mid + 1;
                    else end = mid -1;
                }
                else{
                    if(nums[mid] > target && nums[mid] > nums[0])
                        start = mid + 1;
                    else if(nums[mid] > target && nums[mid] < nums[0])
                        end = mid -1;
                    else
                        start = mid +1;
                }
            }
            else{
                cout << "Start " << start << " Mid " << mid << " End " << end << endl;
                if(target == nums[start]) return start;
                else if(target == nums[end]) return end;
                else return -1;
            }
        }
        return -1;
    }
};
