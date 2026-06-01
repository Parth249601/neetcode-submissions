class Solution {
public:
    int sum(vector<int>& arr){
        int ans = 0;
        for(int num : arr){
            ans += num;
        }
        return ans;
    }
    void backtrack(int start, vector<int>& state, vector<vector<int>>& out, vector<int>& nums, const int& target){
        int n = nums.size();
        int currSum = sum(state);
        if(currSum == target){
            out.push_back(state);
            return;
        }
        if(currSum > target || start >= n) return; //can't lead to a valid solution

        //CHOICE: take this element 
        state.push_back(nums[start]);
        backtrack(start , state, out, nums, target);
        state.pop_back(); //undo

        //CHOICE: do not take this element
        backtrack(start + 1, state, out, nums, target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> out; vector<int> state;
        backtrack(0, state, out, nums, target);
        return out;
    }
};
