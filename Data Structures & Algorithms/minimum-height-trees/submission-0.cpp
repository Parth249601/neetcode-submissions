class Solution {
public:
    int bfs(int src, vector<vector<int>>& adjList, vector<bool>& visited){
        queue<int> qt;
        qt.push(src); visited[src] = true;
        int level = 0;
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                int top = qt.front(); qt.pop();
                for(int v : adjList[top]){
                    if(!visited[v]) {qt.push(v); visited[v] = true;}
                }
            }
            level++;
        }
        return level;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> freq; //maps height, nodes with that height
        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v); adjList[v].push_back(u);
        }
        int minHeight = INT_MAX;
        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            int h = bfs(i, adjList, visited);
            minHeight = min(minHeight, h);
            freq[h].push_back(i);
        }
        return freq[minHeight];
    }
};