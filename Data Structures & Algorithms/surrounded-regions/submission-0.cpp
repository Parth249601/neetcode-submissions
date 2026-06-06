class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(board[r][c] == '#') return;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        int n = board.size(), m = board[0].size();
        board[r][c] = '#';
        for(int k=0; k < 4; k++){
            int rr = r + dr[k];
            int cc = c + dc[k];
            if(rr >= 0 && rr < n && cc>=0 && cc< m && board[rr][cc] == 'O')
                dfs(board, rr, cc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int c = 0; c < m; c++){
            if(board[0][c] == 'O')
                dfs(board, 0, c);
            if(board[n-1][c] == 'O')
                dfs(board, n-1, c);
        }

        for(int r = 0; r < n; r++){
            if(board[r][0] == 'O')
                dfs(board, r, 0);
            if(board[r][m-1] == 'O')
                dfs(board, r, m-1);
        }
        for(int i=0; i< n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};
