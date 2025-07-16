class Solution {
    int alternating(vector<int>& nums){
        // in this we will find alternating subsequence length
        // 0->even,   1->odd
        int n = nums.size(), cnt=1, prev=nums[0]&1;

        for(int i=1; i<n; i++){
            if(prev != (nums[i]&1)){
                prev = nums[i]&1;
                cnt++;
            }
        }

        return cnt;
    }

    int even(vector<int>& nums){
        int n = nums.size(), cnt=0;

        for(auto it : nums){
            if(!(it&1)) cnt++;
        }

        return cnt;
    }
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(), cntEven=even(nums), ans = 2;

        ans = max(ans, cntEven);
        ans = max(ans, n-cntEven);
        ans = max(ans, alternating(nums));

        return ans;        
    }
};