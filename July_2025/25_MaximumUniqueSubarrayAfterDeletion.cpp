class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int last = -1, ans = -1;
        int freq[202] = {0};

        for(auto it: nums){
            if(it > 0 && freq[it+100] < 1) {
                ans += it;
                freq[it+100]++;
            }
            mx = max(mx, it);
        }

        return ans == -1 ? mx : ans+1;
    }
};