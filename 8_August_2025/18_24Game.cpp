class Solution {
    bool f(vector<double>& nums){
        if(nums.size()==1){
            // cout<<nums[0]<<endl;
            if(abs(nums[0]-24) <= 0.1)    return 1;
            return 0;
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                vector<double> rem;
                for(int k=0; k<nums.size(); k++){
                    if(k!=i && k!=j){
                        rem.push_back(nums[k]);
                    }
                }

                double a = nums[i], b = nums[j];
                vector<double> ops = {a+b, a*b, a-b, b-a};

                if(abs(b) != 0)  ops.push_back(a/b);
                if(abs(a) != 0)  ops.push_back(b/a);

                for(auto it : ops){
                    rem.push_back(it);
                    if(f(rem))   return 1;
                    rem.pop_back();
                }
            }
        }

        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;

        for(auto it : cards){
            nums.push_back(1.0*it);
        }

        return f(nums);
    }
};     