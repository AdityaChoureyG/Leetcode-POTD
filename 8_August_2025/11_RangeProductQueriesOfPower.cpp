#define mod 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power, ans;
        for(int i=0; i<30; i++){
            if((1<<i)&n){
                power.push_back((1<<i));
            }
        }

        vector<long long> presum(power.size(), 1);
        presum[0] = power[0];

        for(int i=1; i<power.size(); i++){
            presum[i] = (1ll * presum[i-1] * power[i])%mod;
        }
        // for(auto it : power)    cout<<it<<' ';
        // cout<<endl;
        // for(auto it :  presum)   cout<<it<<' ';

        for(auto it : queries){
            int l = it[0], r = it[1];
            long long temp = 1;
            for(int i=l; i<=r; i++)  {
                temp = (temp * power[i])%mod;
            }
            ans.push_back(temp);
        }
        

        return ans;
    }
};