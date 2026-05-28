class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); if(n == 2) return 1;

        int slow  =0, fast = 0;
        do{
            slow = nums[slow]; // move one step
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        slow = 0;
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
