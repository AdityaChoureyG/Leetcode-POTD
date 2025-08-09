class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        int a = nums[0];

        for(int i=1; i<n-1; i++){
            if(nums[i] == nums[i+1]) continue;

            if(a<nums[i] && nums[i]>nums[i+1])
                cnt++;
            else if(a>nums[i] && nums[i]<nums[i+1])
                cnt++;
            
            a = nums[i];
        }

        return cnt;
    }
};