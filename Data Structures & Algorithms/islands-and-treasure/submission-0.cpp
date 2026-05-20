class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //doesn't form a DAG so no DP, we should prolly use dijkistra
        //it is just bfs from a queue of zeros
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> sources;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0; i < n; i++){
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0){sources.push({i,j}); visited[i][j] = true;}
        }

        const vector<int> dr = {1,-1,0,0};
        const vector<int> dc = {0,0,1,-1};
        int distance = 1;
        while(!sources.empty()){
            int size = sources.size();
            for(int i=0; i<size; i++){
                pair<int,int> cords = sources.front(); sources.pop();
                int r = cords.first, c = cords.second;
                visited[r][c] = true;
                for(int k=0; k<4;k++){
                    int rr = r + dr[k];
                    int cc = c + dc[k];

                    if(rr<n && rr>=0 && cc<m && cc>=0 && !visited[rr][cc] && grid[rr][cc] != -1){
                        sources.push({rr,cc});
                        visited[rr][cc] = true;
                        grid[rr][cc] = distance;
                    }
                }
            }
            distance++;
        }
        return;
    }
};
