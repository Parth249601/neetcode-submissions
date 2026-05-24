class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start = 0;
        for(int i=0; i<n; i++){
            int num = nums2[i];
            for(int j = start; j<m+n; j++){
                if(num < nums1[j]){
                    nums1.insert(nums1.begin()+j, num);
                    start = j+1;
                    break;
                }
                if(nums1[j] == 0 && j >= m){
                    start = j+1;
                    nums1[j] = num;
                    break;
                }
            }
        }
        nums1 = vector<int>(nums1.begin(), nums1.begin() + m + n);
    }
};