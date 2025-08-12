#define mod 1000000007
#define ll long long

class Solution {
    int dp[301][301];

    int power(int n, int x){
        // return n^x
        ll ans = 1;
        while(x--)  {
            ans *= n;
            ans %= mod;
        }

        return ans;
    }

    int f(int i, int rem, int n, int x){
        if(i>n){
            return rem==0;
        }
        if(dp[i][rem]!=-1)   return dp[i][rem];
        ll nt = 0, t = 0, p = power(i, x);
        nt = (nt + f(i+1, rem, n, x))%mod;
        if(p<=rem)  t = (t + f(i+1, rem-p, n, x))%mod;

        return dp[i][rem] = (t + nt)%mod;
    }

public:
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return f(1, n, n, x);
    }
};