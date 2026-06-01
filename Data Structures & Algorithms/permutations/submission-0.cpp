class Solution {
public:
    void backtrack(int start, vector<int>& state ,vector<vector<int>>& out, vector<int>& nums){
        int n = nums.size();
        if(start == n){
            out.push_back(state);
            return;
        }
        if(start > n) return; //no need of this check
        //legal choices are swap num[start] with all the elements ahead of it or just don't swap and move ahead
        //CHOICE 1:
        for(int i = start + 1; i<n; i++){
            swap(state[start], state[i]);
            backtrack(start + 1, state, out, nums);
            swap(state[start], state[i]); //swap back
        }

        //CHOICE 2:
        backtrack(start+1, state, out, nums);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> state= nums;
        vector<vector<int>> out;
        backtrack(0, state, out, nums);
        return out;
    }
};
