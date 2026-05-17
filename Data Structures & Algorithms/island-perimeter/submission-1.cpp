class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,1,-1};
        for(int r=0; r< n; r++){
            for(int c=0; c< m; c++){
                if(grid[r][c] == 1){
                    for(int k =0; k<4; k++){
                        int rr = r + dr[k];
                        int cc = c + dc[k];
                        if(rr < 0 || rr >= n || cc < 0 || cc >= m || grid[rr][cc] == 0) perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};