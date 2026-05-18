class Solution {
public:
    int Area(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        static const int dr[] = {1, -1, 0, 0};
        static const int dc[] = {0, 0, 1, -1};
        int ans = 1;
        if(visited[r][c]) return 0;
        else visited[r][c] = true;
        for(int k =0; k<4; k++){
            int rr = r+ dr[k];
            int cc = c + dc[k];
            if(rr < n && rr>=0 && cc<m && cc>=0 && !visited[rr][cc] &&grid[rr][cc] == 1)
                ans += Area(rr,cc,grid,visited);
        }
        return ans;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int maxArea = 0;
        for(int r=0; r<n; r++){
            for(int c = 0; c<m; c++){
                if(grid[r][c] == 1)
                    maxArea = max(Area(r,c,grid,visited), maxArea);
            }
        }
        return maxArea;
    }
};