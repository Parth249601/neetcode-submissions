class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        //DP is not possible here, it is not a DAG.
        //Dijkistra's with weights as minimum max effort
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        pq.push({0, {m-1,n-1}});
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        d[m-1][n-1] = 0;

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        while(!pq.empty()){
            auto [d_rc, p] = pq.top(); pq.pop();
            int r = p.first, c = p.second;
            if(d_rc > d[r][c]) continue;
            for(int k =0; k<4; k++){
                int rr = r + dr[k];
                int cc = c + dc[k];
                if(rr >=0 && rr <m && cc>= 0 && cc< n){
                    int w = abs(heights[rr][cc] - heights[r][c]);
                    if(max(d_rc, w) < d[rr][cc]){
                        d[rr][cc] = max(d_rc, w);
                        pq.push({d[rr][cc], {rr,cc}});
                    }
                }
            }
        }
        return d[0][0];
    }
};