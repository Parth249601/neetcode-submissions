class Solution {
public:
    vector<int> kahn(vector<vector<int>>& adjList){
        int n = adjList.size();
        //compute in degrees of nodes
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++){
            for(int v : adjList[i])
                indeg[v]++;
        }

        queue<int> qt;
        for(int i=0; i<n; i++)
            if(indeg[i] == 0) qt.push(i);
        vector<int> order;
        while(!qt.empty()){
            int front = qt.front(); qt.pop();
            order.push_back(front);
            for(int v : adjList[front]){
                indeg[v]--;
                if(!indeg[v]) qt.push(v);
            }
        }
        if(order.size() != n) return {};
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(k , vector<int>(k, 0));
        //form a graph from rowConds
        vector<vector<int>> rowGraph(k);
        for(int i=0; i<rowConditions.size(); i++){
            int u = rowConditions[i][0]-1, v = rowConditions[i][1]-1;
            rowGraph[u].push_back(v);
        }

        //Col graph
        vector<vector<int>> colGraph(k);
        for(int i=0; i< colConditions.size(); i++){
            int u = colConditions[i][0]-1, v = colConditions[i][1]-1;
            colGraph[u].push_back(v);
        }

        vector<int> rowOrder = kahn(rowGraph);
        vector<int> colOrder = kahn(colGraph);
        if(!rowOrder.size() || !colOrder.size()) return {};

        unordered_map<int, pair<int,int>> rc;
        for(int i=0; i<rowOrder.size(); i++){
            int num = rowOrder[i];
            rc[num+1] = {i,-1};
        }
        for(int i=0; i<colOrder.size(); i++){
            int num = colOrder[i];
            if(rc[num+1].second == -1) rc[num+1].second = i;
        }

        for(auto [num, p] : rc){
            int r = p.first, c = p.second;
            matrix[r][c] = num;
        }
        
        return matrix;

    }
};