class Solution {
public:
    using minHeap = priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>;
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        d[0][0] = grid[0][0];
        minHeap pq;
        pq.push({d[0][0], 0, 0}); //cost, row, col
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        while(!pq.empty()){
            auto [cost, r, c] = pq.top(); pq.pop();
            if(cost > d[r][c]) continue;
            for(int k =0; k<4; k++){
                int rr = r + dr[k];
                int cc = c + dc[k];
                if(rr >= 0 && rr <m && cc>=0 && cc<n){
                    int w = max(cost, grid[rr][cc]);
                    if(w < d[rr][cc]){
                        d[rr][cc] = w;
                        pq.push({w, rr ,cc});
                    }
                }
            }
        }
        return d[m-1][n-1];
    }
};
