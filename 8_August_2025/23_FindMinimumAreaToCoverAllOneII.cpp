class Solution {
    int minArea(vector<vector<int>>& grid, int a, int b, int c, int d){
        int minrow = INT_MAX, maxrow = -1, mincol=INT_MAX, maxcol = -1;

        // cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;

        for(int i=a; i<=b; i++){
            for(int j=c; j<=d; j++){
                if(grid[i][j]){
                    minrow = min(i, minrow);
                    maxrow = max(i, maxrow);
                    mincol = min(j, mincol);
                    maxcol = max(j, maxcol);
                }
            }
        }

        return minrow==INT_MAX ? INT_MAX/4 : ((maxrow-minrow+1) * (maxcol-mincol+1));
    }
public:
    int minimumSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int res = m*n;

        for(int j=0; j<n-1; j++){
            for(int i=0; i<m-1; i++){
                res = min(res, minArea(grid, 0, i, 0, j) + minArea(grid, i+1, m-1, 0, j) + minArea(grid, 0, m-1, j+1, n-1));

                res = min(res, minArea(grid, 0, m-1, 0, j) + minArea(grid, 0, i, j+1, n-1) + minArea(grid, i+1, m-1, j+1, n-1));
            }
        }

        // cout<<"second"<<endl;

        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                res = min(res, minArea(grid, 0, i, 0, j) + minArea(grid, 0, i, j+1, n-1) + minArea(grid, i+1, m-1, 0, n-1));

                res = min(res, minArea(grid, 0, i, 0, n-1) + minArea(grid, i+1, m-1, 0, j) + minArea(grid, i+1, m-1, j+1, n-1));
            }
        }

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                // splitting col wise
                res = min(res, minArea(grid, 0, m-1, 0, i) + minArea(grid, 0, m-1, i+1, j) + minArea(grid, 0, m-1, j+1, n-1));
            }
        }

        for(int i=0; i<m-2; i++){
            for(int j=i+1; j<m-1; j++){
                // splitting row wise
                res = min(res, minArea(grid, 0, i, 0, n-1) + minArea(grid, i+1, j, 0, n-1) + minArea(grid, j+1, m-1, 0, n-1));
            }
        }

        return res;
        
    }
};