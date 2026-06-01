class Solution {
public:
    int sum(vector<int>& arr){
        int ans = 0;
        for(int num : arr)
            ans += num;
        return ans;
    }
    void backtrack(int start, vector<int>& state, vector<vector<int>> & out, vector<int>& nums, const int& target){
        int n = nums.size();
        int currSum = sum(state);
        if(currSum == target){
            out.push_back(state);
            return;
        }

        if(start >=n || currSum > target) return;

        //CHOICE 1: //Need to do pruning
        for(int i = start; i<=n-1; i++){
            if(i> start && nums[i] == nums[i-1]) continue;
            if(currSum + nums[i] > target) break;
            state.push_back(nums[i]);
            backtrack(i+1, state, out, nums, target);
            state.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> state;
        backtrack(0, state, out, candidates, target);

        
        return out;
    }
};
