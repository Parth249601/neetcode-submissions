class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> new_mat(n, vector<int>(m));
        for(int i=0; i< n; i++){
            for(int j =0; j<m; j++){
                new_mat[i][j] = matrix[j][i];
            }
        }
        return new_mat;
    }
};