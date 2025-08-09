class Solution {
    int n;
    int dp[1001][1001];

    int f1(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& fruits){
        if(i>=n || j>=n-1 || vis[i][j])  return 0;
        // vis[i][j] = 1;
        if(dp[i][j] != -1)  return dp[i][j];
        int a=0, b=0, c=0;

        if(j+1<n && vis[i][j+1]){
            c = f1(i+1, j+1, vis, fruits);
        }
        else{
            a = f1(i-1, j+1, vis, fruits);
            b = f1(i, j+1, vis, fruits);
            c = f1(i+1, j+1, vis, fruits);
        }

        return dp[i][j] =  fruits[i][j] + max(a, max(b, c));
    }

    int f2(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& fruits){
        if(i>=n-1 || j>=n || vis[i][j])  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        // vis[i][j] = 1;
        int a=0, b=0, c=0;

        if(j+1<n && vis[i+1][j]){
            c = f2(i+1, j+1, vis, fruits);
        }
        else{
            a = f2(i+1, j+1, vis, fruits);
            b = f2(i+1, j-1, vis, fruits);
            c = f2(i+1, j, vis, fruits);
        }

        return dp[i][j] = fruits[i][j] + max(a, max(b, c));
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int cnt = 0;
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            cnt += fruits[i][i];
            vis[i][i] = 1;
        }
        int down = f1(n-1, 0, vis, fruits);
        int upper = f2(0, n-1, vis, fruits);
        cnt += down;
        cnt += upper;
        return cnt;
    }
};