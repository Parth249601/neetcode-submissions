class Solution {
public:
    //bfs
    void bfs(int r, int c, vector<vector<char>>& grid){
        if(grid[r][c] == '2') return;
        int n =grid.size();
        int m = grid[0].size();

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        grid[r][c] = -1;
        for(int k=0; k<4; k++){
            int rr = r + dr[k];
            int cc = c + dc[k];
            if(rr <n && rr>=0 && cc<m && cc>=0 && grid[rr][cc] == '1')
                bfs(rr,cc,grid); 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j] == '1'){bfs(i,j,grid); count++;}
            }
        }
        return count;
    }
};