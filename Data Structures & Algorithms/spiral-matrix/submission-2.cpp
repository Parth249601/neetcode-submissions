class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0}; 
        int k = 0;
        //travel in the direction of (r,c) => (r + dr[k%4], c + dc[k%4])
        int r = 0, c = 0; vector<vector<bool>> visited(m, vector<bool>(n, false));
        while(ans.size() != m*n){
            ans.push_back(matrix[r][c]);
            visited[r][c] = true;

            int next_r = r + dr[k % 4];
            int next_c = c + dc[k % 4];
            
            if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n || visited[next_r][next_c]) {
                k++; 
                next_r = r + dr[k % 4];
                next_c = c + dc[k % 4];
            }
            r = next_r; c = next_c;
        }
        return ans;
    }
};
