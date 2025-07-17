class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // this problem is based on simple lis pattern
        // catch is mod only
        // what we can do is we can run simple lis for long sub having 0, then 1, then 2, ...... so on , till mod is k-1
        //but it that case tc will be k*n^2  which give tle

        // so what we can do is we will take 2-D vector of size [k][n]
        // store the result for that mod 


        int n = nums.size(), mx = 2;
        vector<vector<int>> dp(k, vector<int>(n, 1));

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                int mod = (nums[i] + nums[j])%k;
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                mx = max(mx, dp[mod][i]);
            }
        }

        return mx;
    }
};