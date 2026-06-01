class Solution {
public:
    void undo(vector<int>& state){
        state.pop_back();
    }
    void backtrack(int start, vector<int>& state, vector<vector<int>>& out, vector<int>& nums){
        int n = nums.size();
        if(start == n){ // we have finished exploring all the nodes
            out.push_back(state);
            return;
        }
        if(start < 0) return; //no need but for completeness sake

        //there are two legal choice appending nums[start] and not appending nums[start];
        //CHOICE 1: APPENDING
        state.push_back(nums[start]); //apply
        backtrack(start + 1, state, out, nums);
        undo(state);

        //CHOICE 2: NOT APPENDING
        backtrack(start + 1, state, out, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> state;
        backtrack(0, state, out, nums);
        return out;
    }
};
