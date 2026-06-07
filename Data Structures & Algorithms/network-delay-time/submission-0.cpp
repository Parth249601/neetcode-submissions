class Solution {
public:
    void dijkistra(int src, vector<vector<pair<int,int>>>& adjList, vector<long long>& d){
        d[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto [du, u] = pq.top(); pq.pop();
            if(du > d[u]) continue;
            for(auto [v,w] : adjList[u]){
                if(du + w < d[v]){
                    d[v] = du + w;
                    pq.push({d[v], v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(int i=0; i< times.size(); i++){
            int u = times[i][0]-1, v = times[i][1]-1, w = times[i][2];
            adjList[u].push_back({v,w});
        }
        k--;

        vector<long long> d(n, LLONG_MAX);
        dijkistra(k, adjList, d);
        long long ans = *max_element(d.begin(), d.end());
        return ans == LLONG_MAX ? -1 : (int) ans;
    }
};
