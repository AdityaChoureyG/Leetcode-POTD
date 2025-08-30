class Solution {
    bool checkCol(vector<vector<char>>& board, int r, int c){
        for(int i=0; i<9; i++){
            if(i==r)    continue;
            if(board[i][c] == board[r][c])  return false;
        }
        return true;
    }

    bool checkRow(vector<vector<char>>& board, int r, int c){
        for(int j=0; j<9; j++){
            if(j==c)    continue;
            if(board[r][j] == board[r][c])  return false;
        }
        return true;
    }

    bool checkInBox(vector<vector<char>>& board, int r, int c){
        int x = r/3;
        int y = c/3;

        int str = x*3;
        int stc = y*3;

        for(int i=str; i<str+3; i++){
            for(int j=stc; j<stc+3; j++){
                if(i==r && j==c)    continue;
                if(board[i][j] == board[r][c])  return false;
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(!checkRow(board, i, j))  return false;
                    if(!checkCol(board, i, j))  return false;
                    if(!checkInBox(board, i, j))  return false;
                }
            }
        }

        return 1;
    }
};