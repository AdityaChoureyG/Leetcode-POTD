#include<bits/stdc++.h>

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int freq[10002] = {0};
        int n = nums.size();
        int ans = 0, sum = 0;

        int i=0, j=0;
        while(j<n){
            freq[nums[j]]++;
            sum += nums[j];
            while(freq[nums[j]] > 1){
                sum -= nums[i];
                freq[nums[i]]--;
                i++;
            }
            // cout<<i<<' '<<j<<endl;
            ans = max(sum, ans);
            j++;
        }

        return ans;
    }
};