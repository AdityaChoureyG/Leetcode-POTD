class Solution {

    bool isSafe(int& r, int& c, char& ch, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            
            if(board[i][c] == ch)  return false;
        }

        for(int j=0; j<9; j++)   {
            
            if(board[r][j] == ch)    return false;
        }

        int nr = (r/3)*3, nc = (c/3)*3;

        for(int i=nr; i<nr+3; i++){
            for(int j=nc; j<nc+3; j++){
                if(board[i][j] == ch)  return false;
            }
        }

        return true;
    }
    int f(int i, int j, vector<vector<char>>& board){
        if(i==9){
            return 1;
        }
        if(j==9)   return f(i+1, 0, board);
        if(board[i][j] != '.')   return f(i, j+1, board);

        for(char k='1'; k<='9'; k++){
            // if(i==1 && j==8)  cout<<k<<endl;;
            if(isSafe(i, j, k, board)){
                board[i][j] = k;
                if(f(i, j+1, board))  return 1;
                board[i][j] = '.';
            }
        }

        return 0;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int x = f(0, 0, board);
    }
};