#define ll long long

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflictingPt(n+1);
        vector<ll> extra(n+1, 0);
        ll valid = 0, mxex = 0;

        for(auto it : conflictingPairs){
            int a = min(it[0], it[1]);
            int b = max(it[0], it[1]);

            conflictingPt[b].push_back(a);
        }

        int mxcp = 0, smxcp = 0;

        for(int end=1; end<=n; end++){
            
            for(auto it : conflictingPt[end]){
                if(it > mxcp){
                    smxcp = mxcp;
                    mxcp = it;
                }
                else if(it > smxcp){
                    smxcp = it;
                }
            }

            valid += end - mxcp;
            // extra after removing mxcp 
            extra[mxcp] += mxcp - smxcp;
            if(mxex < extra[mxcp])   mxex = extra[mxcp];
        }

        return valid + mxex;
    }
};