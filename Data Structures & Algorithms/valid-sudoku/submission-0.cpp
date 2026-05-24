class Solution {
public:
    bool isValid_row(vector<vector<char>>& board, int row){
        unordered_set<char> nums; int i = row; 
        for(int j =0; j<9; j++){
            if(board[i][j] == '.') continue;
            bool seen_ij = (nums.find(board[i][j]) != nums.end());
            if(seen_ij) return false;
            else nums.insert(board[i][j]);
        }
        return true;
    }

    bool isValid_col(vector<vector<char>>& board, int col){
        unordered_set<char> nums; int j = col; 
        for(int i =0; i<9; i++){
            if(board[i][j] == '.') continue;
            bool seen_ij = (nums.find(board[i][j]) != nums.end());
            if(seen_ij) return false;
            else nums.insert(board[i][j]);
        }
        return true;
    }

    bool isValid_box(vector<vector<char>>& board, int row, int col){
        unordered_set<char> nums; int i = row, j =  col;
        for(int i= row; i <= row+2; i++){
            for(int j = col; j <= col + 2; j++){
                if(board[i][j] == '.') continue;
                bool seen_ij = (nums.find(board[i][j]) != nums.end());
                if(seen_ij) return false;
                else nums.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //check if all rows and cols are valid
        for(int i=0; i< 9; i++){
            if(!isValid_row(board, i) || !isValid_col(board,i)) return false;
        }
        //check if every box is ok
        for(int i=0; i< 9; i += 3){
            for(int j =0; j<9; j+= 3)
                if(!isValid_box(board,i,j)) return false;
        }
        return true;

    }
};
