class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minrow = INT_MAX, maxrow = -1, mincol=INT_MAX, maxcol = -1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    minrow = min(i, minrow);
                    maxrow = max(i, maxrow);
                    mincol = min(j, mincol);
                    maxcol = max(j, maxcol);
                }
            }
        }

        int h = maxrow - minrow + 1, w = maxcol - mincol + 1;
        return h*w;
    }
};