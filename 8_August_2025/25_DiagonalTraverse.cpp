class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        // ans.push_back(mat[0][0]);
        int m = mat.size(), n = mat[0].size();

        if(m==1){
            // single row
            for(int i=0; i<n; i++)   ans.push_back(mat[0][i]);
            return ans;
        }

        if(n==1){
            // single col
            for(int i=0; i<m; i++)   ans.push_back(mat[i][0]);
            return ans;
        }

        int i=0, j=0;
        ans.push_back(mat[0][0]);

        while(true){
            if(i==m-1 && j==n-1)  break;
            if(i==0 || j==n-1){
                // go down diagonally
                if(j==n-1)   i++;
                else     j++;

                ans.push_back(mat[i][j]);

                while(!(j==0 || i==m-1)){
                    i++;
                    j--;
                    ans.push_back(mat[i][j]);
                }
            }
            else if(j==0 || i==m-1){
                // go up diagonally
                if(i==m-1)   j++;
                else   i++;

                ans.push_back(mat[i][j]);

                while(!(i==0 || j==n-1)){
                    i--;
                    j++;
                    ans.push_back(mat[i][j]);
                }
            }
        }

        return ans;
    }
};