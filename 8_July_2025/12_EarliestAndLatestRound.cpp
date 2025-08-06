#include<bits/stdc++.h>

class Solution {
    int N=0, mn = INT_MAX, mx = INT_MIN, f, s;
    int dp[27][27][27];

    void fun(int mask, int i, int j, int round, int l, int m, int r){
        if(i >= j){
            // round completed
            fun(mask, 0, N, round+1, l, m, r);
        }
        else if((mask&(1<<i)) == 0){
            // ith bit is not set
            fun(mask, i+1, j, round, l, m, r);
        }
        else if((mask&(1<<j)) == 0){
            // jth bit is not set
            fun(mask, i, j-1, round, l, m, r);
        }
        else if(i==f && j==s){
            // first and second conflict
            mn = min(mn, round);
            mx = max(mx, round);
        }
        else if(dp[l][m][r]==-1){
            dp[l][m][r] = 1;
            if(i!=f && i!=s){
                // i might die
                fun(mask^(1<<i), i+1, j-1, round, l-(i<f), m-(f<i && i<s), r-(i>s));
            }
            if(j!=f && j!=s){
                // j might die
                fun(mask^(1<<j), i+1, j-1, round, l-(j<f), m-(f<j && j<s), r-(j>s));
            }
            // battleground
            // if(i==f || i==s){
            //     // i surely win
            //     fun(mask^(1<<j), i+1, j-1, round);
            // }
            // else if(j==f || j==s){
            //     // j surely win, i will dead
            //     fun(mask^(1<<i), i+1, j-1, round);
            // }
            // else{
            //     // check for both i and j
            //     fun(mask^(1<<i), i+1, j-1, round);
            //     fun(mask^(1<<j), i+1, j-1, round);
            // }
        }
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n-1, f = firstPlayer-1, s = secondPlayer-1;
        int mask = (2<<n)-1;
        memset(dp, -1, sizeof(dp));
        fun(mask, 0, n-1, 1, f, s-f-1, N-s);
        return {mn, mx};
    }
};