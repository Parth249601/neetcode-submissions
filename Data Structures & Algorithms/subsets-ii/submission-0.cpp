class Solution {
public:
    void backtrack(int start, vector<int>& state, vector<vector<int>>& out, vector<int>& nums, set<vector<int>>& seen){
        int n = nums.size();
        if(start == n){
            if(seen.count(state)) return;
            seen.insert(state);
            out.push_back(state);
            return;
        }
        if(start > n) return;

        //CHOICE 1:
       
        state.push_back(nums[start]);
        backtrack(start + 1, state, out, nums, seen);
        state.pop_back();
        

        //CHOICE 2:
        backtrack(start + 1, state, out, nums, seen);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> seen;
        vector<vector<int>> out; vector<int> state;
        backtrack(0, state, out, nums, seen);
        return out; 
    }
};
