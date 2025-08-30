class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for(int r=0; r<n; r++){
            // sort diagonally in descending order
            int i=r, j=0;
            vector<int> temp;
            while(i<n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = r;
            j = 0;
            int k = temp.size()-1;
            while(i<n){
                ans[i][j] = temp[k];
                i++;
                j++;
                k--;
            }
        }

        for(int c=1; c<n; c++){
            int i=0, j=c;
            vector<int> temp;
            while(j<n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = 0;
            j = c;
            int k = 0;
            while(j<n){
                ans[i][j] = temp[k];
                i++;
                j++;
                k++;
            }
        }

        return ans;
    }
};