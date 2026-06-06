class Solution {
public:
    void dfs(int src, vector<vector<int>>& adjList, vector<bool>& visited){
        if(visited[src]) return;
        visited[src] = true;
        for(int v : adjList[src]){
            if(!visited[v])
                dfs(v, adjList, visited);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        dfs(0, adjList, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
