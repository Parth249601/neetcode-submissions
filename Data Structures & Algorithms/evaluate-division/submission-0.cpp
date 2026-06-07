class Solution {
public:
    double dfs(string src, string target, unordered_map<string, vector<pair<string, double>>>& adjList, unordered_map<string, bool>& visited){
        if(src == target) return 1;
        visited[src] = true;
        for(auto [s, w] : adjList[src]){
            if(!visited[s]){
                double rem = dfs(s, target, adjList, visited);
                if(rem != -1) return w * rem;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string, vector<pair<string, double>>> adjList;
       unordered_set<string> seen;
       for(int i=0; i< equations.size(); i++){
            string a = equations[i][0], b = equations[i][1];
            seen.insert(a); seen.insert(b);
            adjList[a].push_back({b, values[i]});
            adjList[b].push_back({a, 1/values[i]});
        }
        
        vector<double> ans;
        for(int i=0; i< queries.size(); i++){
            unordered_map<string, bool> visited;
            string src = queries[i][0], target= queries[i][1];
            if(seen.count(src) && seen.count(target))
                ans.push_back(dfs(src, target, adjList, visited));
            else
                ans.push_back((double)-1);
        }
        return ans;
    }
};