class Solution {

    double f(int a, int b, vector<vector<double>>& dp){
        if(a<=0 && b<=0)  return 0.5;
        else if(a<=0)   return 1;
        else if(b<=0)   return 0;

        if(dp[a][b] != -1)    return dp[a][b];

        double x = 0;
        x += f(a-100, b, dp);
        x += f(a-75, b-25, dp);
        x += f(a-50, b-50, dp);
        x += f(a-25, b-75, dp);

        return dp[a][b] = 0.25 * x;
    }
public:
    double soupServings(int n) {
        if(n > 5000) return 1;
        vector<vector<double>> dp(5001, vector<double>(5001, -1));
        return f(n, n, dp);
    }
};