class Solution {
public:
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        int i = left, j = mid + 1;
        int k =0;

        vector<int> temp(right-left+1);

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        
        for (i = 0; i < k; i++) {
            nums[left + i] = temp[i];
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};