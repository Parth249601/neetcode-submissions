class Solution {
public:
    int bfs_maxDist(vector<vector<int>>& grid,queue<pair<int,int>>& qt){
        //if we visted a cell we will make grid[i][j] = -2; 
        int n = grid.size(); int distance = 0;
        int m = grid[0].size();
        
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!qt.empty()){
            int size = qt.size();
            for(int i=0; i< size; i++){
                pair<int,int> p = qt.front(); qt.pop();
                grid[p.first][p.second] = -2;
                for(int k = 0; k<4; k++){
                    int rr = p.first + dr[k];
                    int cc = p.second + dc[k];

                    if(rr<n && rr>=0 && cc<m && cc>=0 && grid[rr][cc] != -2 && grid[rr][cc] == 1){
                        qt.push({rr,cc});
                        grid[rr][cc] = -2;
                    }
                }
            }
            // Only increment distance if there are actually more levels to explore
            if (!qt.empty())
                distance++;
        }
        return distance;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       //find an unvisited rotten orange bfs from there store max distance to a fresh orange
       //repeat until no unvisited rotten oranges
       //if there is still a fresh orange return -1;
       //else return max distance
        int n = grid.size();
        int m = grid[0].size();
        int maxDistance = 0;
        queue<pair<int,int>> qt;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2)
                    qt.push({i,j});
            }
        }
        int distance = bfs_maxDist(grid, qt);

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return distance;
    }
};