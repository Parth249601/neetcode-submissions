class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); stack<pair<int,int>> st;
        for(int i=0; i<n; i++){
            if(st.empty()) {st.push({i, temperatures[i]}); continue;}

            while(!st.empty() && st.top().second < temperatures[i]){
                ans[st.top().first] = i - st.top().first; st.pop();
            }            

            st.push({i, temperatures[i]});


        }
        return ans;
    }
};
