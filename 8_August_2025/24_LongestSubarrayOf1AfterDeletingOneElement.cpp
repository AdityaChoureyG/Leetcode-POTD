class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int i=0, j=0;
        int extra = 0;

        while(j<n){
            if(nums[j]==0) extra++;
            
            if(extra > 1){
                if(nums[i]==0)   extra--;
                i++;
            }
            // cout<<i<<' '<<j<<endl;
            ans = max(ans, j-i);
            j++;
        }

        return ans;
    }
};