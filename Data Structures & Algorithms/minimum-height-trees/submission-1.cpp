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
        if (n == 1) return {0};

        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);

        // Build adjacency list and populate the degrees
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        
        // Push all initial leaf nodes (degree == 1) into the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        int remainingNodes = n;
        
        while (remainingNodes > 2) {
            int size = leaves.size();
            remainingNodes -= size; 
            
            for (int i = 0; i < size; i++) {
                int leaf = leaves.front(); leaves.pop();
                for (int neighbor : adjList[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        vector<int> minHeightRoots;
        while (!leaves.empty()) {
            minHeightRoots.push_back(leaves.front());
            leaves.pop();
        }

        return minHeightRoots;
    }
};