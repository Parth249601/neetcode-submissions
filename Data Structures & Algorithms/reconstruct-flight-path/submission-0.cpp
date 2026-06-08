class Solution {
public:
    void dfs(string src, unordered_map<string, vector<string>>& adjList, vector<string>& ans){
        while(!adjList[src].empty()){
            string next = adjList[src].back();
            adjList[src].pop_back();
            dfs(next, adjList, ans);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjList;
        for(int i = 0; i< tickets.size(); i++){
            string from = tickets[i][0], to = tickets[i][1];
            adjList[from].push_back(to);
        }
        for(auto& [s, vec] : adjList)
            sort(vec.begin(), vec.end(), greater<string>());
        vector<string> ans;
        string start = "JFK";
        dfs(start, adjList, ans);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
