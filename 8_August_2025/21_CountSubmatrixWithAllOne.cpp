class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> row(m, vector<int>(n, 0));
        int ans = 0;

        for(int i=0; i<m; i++){
            row[i][0] = mat[i][0];
            for(int j=1; j<n; j++){
                if(mat[i][j] == 0)    row[i][j] = 0;
                else    row[i][j] = 1 + row[i][j-1];
            }

            for(int j=0; j<n; j++){
                int cur = row[i][j];
                for(int k=i; k>=0; k--){
                    cur = min(cur, row[k][j]);
                    if(cur==0) break;
                    ans += cur;
                }
            }
        }

        return ans;
    }
};