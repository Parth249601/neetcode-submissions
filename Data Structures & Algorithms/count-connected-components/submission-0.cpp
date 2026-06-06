class Solution {
public:
    void dfs(int src, vector<vector<int>>& adjList, vector<bool>& visited){
        if(visited[src]) return;
        visited[src] = true;
        for(int v : adjList[src]){
            if(!visited[v]) dfs(v, adjList, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(int i=0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adjList, visited);
                count++;
            }
        }
        return count;
    }
};
