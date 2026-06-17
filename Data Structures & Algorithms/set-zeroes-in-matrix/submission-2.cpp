class Solution {
public:
    void set_zero(vector<vector<int>>& matrix, int row, int col, vector<vector<bool>>& visited){
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[row][i] == 0) continue;
            matrix[row][i] = 0;
            visited[row][i] = true;
        }
        for(int i =0; i<m; i++){
            if(matrix[i][col] == 0) continue;
            matrix[i][col] = 0;
            visited[i][col] = true;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(!visited[i][j]){
                    if(matrix[i][j] == 0) set_zero(matrix, i, j, visited);
                    visited[i][j] = true;
                }
            }
        }   
    }
};
