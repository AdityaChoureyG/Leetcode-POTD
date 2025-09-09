#define mod 1000000007
#define ll long long

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<ll, ll>> q;
        ll cnt = 0;
        q.push({1, 1});

        for(int i=1; i<n; i++){
            ll sz = q.size();
            ll newbee = 0;

            while(sz--){
                auto cur = q.front();
                q.pop();
                cur.second++;
                cur.second %= mod;
                if(cur.second > forget)  continue;
                if(cur.second > delay){
                    newbee += cur.first;
                    newbee %= mod;
                }
                q.push(cur);
                if(i==n-1){
                    cnt += cur.first;
                    cnt %= mod;
                }
            }

            if(newbee > 0)  q.push({newbee, 1});
            if(i==n-1)  {
                cnt = (cnt + newbee)%mod;
            }
        }

        return cnt;
    }
};