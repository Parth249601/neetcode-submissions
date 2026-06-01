class Solution {
public:
    void backtrack(int start, vector<int>& state, vector<vector<int>> & out, const int& n, const int& k){
        //when to stop start >n or state.size() > k
        if(state.size() == k){
            out.push_back(state);
            return;
        }
        if(start > n || state.size() > k) return; //no need 

        //Choices
        //Choose to take start or start + 1, .... all the elements
        for(int i = start; i<=n; i++){
            state.push_back(i);
            backtrack(i+1, state, out, n, k);
            state.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> state;
        backtrack(1, state, out, n, k);
        return out;
    }
};