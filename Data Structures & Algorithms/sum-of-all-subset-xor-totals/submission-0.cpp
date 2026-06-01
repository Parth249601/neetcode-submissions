class Solution {
public:
    int xor_total(vector<int>& nums){
        int ans = 0;
        for(int num : nums)
            ans = ans ^ num;
        return ans;
    }
    void undo(vector<int>& state){
        state.pop_back();
    } 
    void backtrack(int start, vector<int>& state, vector<int>& nums,int& ans){ //s defines where we are at in the arr nums
        int n = nums.size();

        if(start == n){ //it is a complete solution, I have made decision about every node
            ans += xor_total(state); 
            return;
        }
        if(start < 0 || start >= n) return;

        //we need to define legal choices from here -> append every subset from remaining elements to start and move to start + 1, resetting the vector state 
        //legal choice is either I include it or skip it
        //appending state by including start and exploring and undoing
        state.push_back(nums[start]); //applied
        backtrack(start + 1, state, nums, ans);
        undo(state);
        //appending state by not including start and exploring and undoing
        backtrack(start + 1, state, nums, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> state; int ans = 0;
        backtrack(0, state, nums, ans);
        return ans;
    }
};