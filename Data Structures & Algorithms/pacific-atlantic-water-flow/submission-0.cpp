class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[r][c]) return;
        int n = heights.size();
        int m = heights[0].size();
        visited[r][c] = true;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        for(int k=0; k<4; k++){
            int rr = r + dr[k];
            int cc = c + dc[k];
            if(rr<n&& rr>=0 && cc<m && cc>=0 && !visited[rr][cc] && heights[rr][cc] >= heights[r][c])
                dfs(rr,cc,heights, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //dfs from atlantic visited[cell] = -1, //dfs from pacific, visited[cell] = -2
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> visited_atlantic(n, vector<bool>(m, false));
        vector<vector<bool>> visited_pacific(n, vector<bool>(m, false));
        for(int c = 0; c<m; c++){
            dfs(0,c,heights, visited_pacific);
            dfs(n-1,c,heights,visited_atlantic);
        }
        for(int r=0; r<n;r++){
            dfs(r,0,heights, visited_pacific);
            dfs(r,m-1,heights, visited_atlantic);
        }

        vector<vector<int>> results;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(visited_atlantic[i][j] && visited_pacific[i][j]) results.push_back({i,j});
            }
        }
        return results;
    }
};