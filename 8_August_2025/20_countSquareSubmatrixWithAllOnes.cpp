class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        int cnt = 0;

        for(int i=0; i<m; i++){
            // row wise filling first col
            table[i+1][0+1] = matrix[i][0] + table[i+1-1][0+1];
            if(matrix[i][0]) cnt++;
        }

        for(int i=0; i<n; i++){
            // column wise filling first row
            table[0+1][i+1] = matrix[0][i] + table[0+1][i-1+1];
            if(matrix[0][i])  cnt++;
        }

        if(matrix[0][0])    cnt--;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j])    cnt++;
                table[i+1][j+1] = matrix[i][j] + table[i+1][j-1+1] + table[i-1+1][j+1] - table[i-1+1][j-1+1];
            }
        }

        // for(int i=0; i<=m; i++){
        //     for(int j=0; j<=n; j++)   cout<<table[i][j]<<' ';
        //     cout<<endl;
        // }

        for(int sz=2; sz<=min(m, n); sz++){
            for(int i=sz; i<=m; i++){
                for(int j=sz; j<=n; j++){
                    int temp = table[i][j] - table[i-sz][j] - table[i][j-sz] + table[i-sz][j-sz];
                    if(temp == (sz*sz))      cnt++;
                }
            }
        }

        return cnt;
    }
};