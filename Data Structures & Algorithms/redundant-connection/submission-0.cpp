class Solution {
public:
    bool get_cycle(int src, vector<int>& parent, vector<vector<int>>& adjList, vector<bool>& visited, unordered_set<int>& cycle){
        visited[src]= true;
        for(int v : adjList[src]){
            if(!visited[v]){
                parent[v] = src;
                if(get_cycle(v, parent, adjList, visited, cycle))
                    return true;
            }
            else if(v != parent[src]){
                cycle.insert(v);
                int curr = src;
                while(curr != v){
                    cycle.insert(curr);
                    curr = parent[curr];
                }
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 1 + edges.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v); adjList[v].push_back(u);
        }

        vector<int> parent(n); vector<bool> visited(n, false); 
        unordered_set<int> cycle;
        if(get_cycle(1,parent, adjList, visited, cycle)){
            for(auto i : cycle)
                cout << i << " ";
            cout << endl;
        } 

        vector<int> last_edge;
        for(int i=0; i< edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)) last_edge = edges[i];
        }
        return last_edge;



    }
};
