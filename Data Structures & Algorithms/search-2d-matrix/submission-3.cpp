class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        //locate the row in which target is potentially present;
        int row;
        for(row = 0; row <m; row++){
            if(target >= matrix[row][0] && target <= matrix[row][n-1]){
                break; 
            }
        }
       if(row == m) return false;

        //I have the row now
        vector<int> nums = matrix[row];
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start+ (end - start)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};
