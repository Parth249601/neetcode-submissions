class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& adjList, vector<bool>& visited){
        if(src == target) return true;
        visited[src] = true;
        for(int v : adjList[src]){
            if(!visited[v])
                if(dfs(v, target, adjList, visited)) return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjList[u].push_back(v);
        }
        vector<bool> ans;

        for(int i = 0; i<queries.size(); i++){
            int u = queries[i][0], v = queries[i][1];
            vector<bool> visited(numCourses, false);
            if(dfs(u,v,adjList, visited)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;


    }
};