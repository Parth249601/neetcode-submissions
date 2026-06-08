class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(int i =0; i< flights.size(); i++){
            int u = flights[i][0], v= flights[i][1], w = flights[i][2];
            adjList[u].push_back({v,w});
        }        
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        queue<pair<int,int>> qt; //node,cost;
        qt.push({src, 0});
        int stops = 0;
        while(!qt.empty() && stops <= k){
            int size = qt.size();
            while(size--){
                auto [u, du] = qt.front(); qt.pop();
                for(auto [v, w] : adjList[u]){
                    if(du + w < minCost[v]){
                        minCost[v] = du + w;
                        qt.push({v, minCost[v]});
                    } 
                }
            }
            stops++;
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
