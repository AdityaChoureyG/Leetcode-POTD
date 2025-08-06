class Solution {
    int n;
    int cnt;
    int mxor;

    void mxxor(int i, vector<int>& nums, int x){
        if(i==n)  {
            // cout<<x<<endl;
            if(x == mxor) cnt++;
            return;
        }

        int nt = 0, t = 0;

        // no take
        mxxor(i+1, nums, x);

        //take
        mxxor(i+1, nums, x|nums[i]);

        x &= (!nums[i]);


    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        cnt = 0;
        mxor = 0;
        for(auto it : nums)  mxor |= it;
        mxxor(0, nums, 0);
        // cout<<mxor;
        return cnt;
    }
};