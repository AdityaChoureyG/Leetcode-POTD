class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int lon = 1,cnt = 0;

        for(int i=0; i<n; i++)  mx = max(mx, nums[i]);

        for(int i=0; i<n; i++){
            if(nums[i] == mx){
                cnt++;
                lon = max(lon, cnt);
            }
            else cnt = 0;
        }

        return lon;
    }
};