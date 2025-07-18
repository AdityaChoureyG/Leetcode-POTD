#define ll long long

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n/3;
        ll ans = LLONG_MAX;
        vector<ll> first(n, -1), second(n, -1);

        // we will store minimum possible sum by taking n element for each indices >= i if possible
        priority_queue<int> mxpq;
        ll mnsum = 0;
        for(int i=0; i<m; i++)  {
            mnsum += nums[i];
            mxpq.push(nums[i]);
        }
        first[m-1] = mnsum;
        for(int i=m; i<n-m; i++){
            if(nums[i] < mxpq.top()){
                mnsum -= mxpq.top();
                mxpq.pop();
                mnsum += nums[i];
                mxpq.push(nums[i]);
            }
            first[i] = mnsum;
        }

        // now in second array we will store maximum possible sum of n element for each indices > i if possible
        priority_queue<int, vector<int>, greater<int>> mnpq;
        ll mxsum = 0;
        for(int i=n-m; i<n; i++){
            mxsum += nums[i];
            mnpq.push(nums[i]);
        }
        
        for(int i=n-m-1; i>=0; i--){
            second[i] = mxsum;
            if(nums[i] > mnpq.top()){
                mxsum -= mnpq.top();
                mnpq.pop();
                mxsum += nums[i];
                mnpq.push(nums[i]);
            }
        }

        // for(auto it : first)  cout<<it<<' ';
        // cout<<endl;
        // for(auto it : second)  cout<<it<<' ';

        for(int i=0; i<n; i++){
            if(first[i]!=-1 && second[i]!=-1)
                ans = min(ans, first[i]-second[i]);
        }


        return ans;
    }
};                                                                                        