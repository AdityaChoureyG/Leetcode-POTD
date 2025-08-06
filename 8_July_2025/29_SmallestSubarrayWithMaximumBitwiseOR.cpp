class Solution {

    int f(int mid, int st, vector<int>& preor, vector<int>& mx){
        int oor = preor[mid];
        // cout<<'o'<<oor<<endl;
        if(st != 0)    {
            oor = oor & (~preor[st-1]);
            cout<<preor[mid]<<' '<<~preor[st-1]<<endl;
        }

        // cout<<"oor"<<mid<<' '<<oor<<endl;

        return oor;
    }

    int bs(int st, vector<int>& preor, vector<int>& mx, vector<int>& nums){
        int lo = st,  hi = nums.size()-1, idx = lo;
        // cout<<"idx "<<st<<" st "<<mx[st]<<endl;

        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(f(mid, st, preor, mx)==mx[st]){
                idx = mid;
                hi = mid - 1;
            }
            else    lo = mid + 1;
        }

        // cout<<idx<<' '<<st<<' '<<lo<<' '<<hi<<endl;

        return idx - st + 1;
    }

public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);
        vector<int> bit(32, 0);
        int mx = n-1;

        for(int i=n-1; i>=0; i--){
            // checking for each ith no
            mx = i;

            for(int j=0; j<32; j++){
                // checking if jth bit of ith no is set 
                if(nums[i] & (1<<j)){
                    // jth bit is set of ith no
                    bit[j] = i;
                }
                mx = max(mx, bit[j]);
                // cout<<bit[j]<<' ';
            }
            // cout<<endl;            

            ans[i] = mx - i + 1;
        }

        return ans;
    }
};