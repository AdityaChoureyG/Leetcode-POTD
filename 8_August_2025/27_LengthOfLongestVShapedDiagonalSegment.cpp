class Solution {
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};
    int m, n;
    vector<vector<int>> v;

    bool valid(int ni, int nj, int x){
        if(ni<0 || nj<0 || ni>=m || nj>=n || v[ni][nj]!=x)   return false;
        return true;
    }

    int f(int i, int j, bool tt, int prevmove, int seq){
        
        int dist = 0;
        int x;
        if(seq == 2)  x = 0;
        else   x  = 2;

        // cout<<i<<' '<<j<<' '<<tt<<' '<<prevmove<<' '<<seq<<endl;

        if(prevmove==-1){
            // explore all direction
            int temp = 0;
            for(int k=0; k<4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(valid(ni, nj, seq)){
                    temp = max(temp, f(ni, nj, tt, k, x));
                }
            }
            dist = temp;
        }
        else if(tt==false){
            // turn not taken the we can take turn other two diection
            int temp = 0;
            // if(prevmove%2==0){
            //     // turn to odd dx dy
            //     for(int k=1; k<4; k+=2){
            //         int ni = i + dx[k];
            //         int nj = j + dy[k];
            //         if(valid(ni, nj, seq)){
            //             temp = max(temp, f(ni, nj, true, k, x));
            //         }
            //     }
            // }
            // else{
            //     // turn to even dx dy
            //     for(int k=0; k<4; k+=2){
            //         int ni = i + dx[k];
            //         int nj = j + dy[k];
            //         if(valid(ni, nj, seq)){
            //             temp = max(temp, f(ni, nj, true, k, x));
            //         }
            //     }
            // }

            // we can only make clockwise turn
            // k  0->1, 1->2, 2->3, 3->1
            int k = prevmove;
            if(k==3){
                int ni = i + dx[0];
                int nj = j + dy[0];
                if(valid(ni, nj, seq)){
                    temp = max(temp, f(ni, nj, true, 0, x));
                }
            }
            else{
                int ni = i + dx[k+1];
                int nj = j + dy[k+1];
                if(valid(ni, nj, seq)){
                    temp = max(temp, f(ni, nj, true, k+1, x));
                }
            }
            int ni = i + dx[prevmove];
            int nj = j + dy[prevmove];
            if(valid(ni, nj, seq)){
                temp = max(temp, f(ni, nj, tt, prevmove, x));
            }

            dist = temp;
        }
        else{
            // you can go only in prevmove direction
            int ni = i + dx[prevmove];
            int nj = j + dy[prevmove];
            if(valid(ni, nj, seq)){
                dist = f(ni, nj, tt, prevmove, x);
            }
        }

        return dist + 1;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        v = grid;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int t = f(i, j, false, -1, 2);
                    ans = max(ans, t);
                    // cout<<i<<' '<<j<<' '<<t<<endl;
                }
            }
        }

        return ans;
    }
};

