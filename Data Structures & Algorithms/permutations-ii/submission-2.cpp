class Solution {
public:
    void backtrack(int start, vector<int>& state ,vector<vector<int>>& out, vector<int>& nums){
        int n = nums.size();

        cout << "enter start=" << start << " state= ";
        for(int x : state) cout << x << " "; cout << "\n";
        if(start == n){
            out.push_back(state);
            return;
        }
        if(start > n) return; //no need of this check
        //legal choices are swap num[start] with all the elements ahead of it or just don't swap and move ahead
        //CHOICES:
        unordered_set<int> seen;
        for(int i = start; i<n; i++){
            if(seen.count(state[i])) continue; //pruning
            seen.insert(state[i]);
            swap(state[start], state[i]);
            backtrack(start + 1, state, out, nums);
            swap(state[start], state[i]); //swap back
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> state= nums;
        vector<vector<int>> out;
        backtrack(0, state, out, nums);
        return out;
    }
};