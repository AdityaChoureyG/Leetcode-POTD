class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)  return {0};

        vector<int> ans;
        if(n&1){
            ans.push_back(0);
            n--;
            int x = 1;
            while(n){
                ans.push_back(x);
                ans.push_back(-1*x);
                x++;
                n -= 2;
            }
        }
        else{
            int x = 1;
            while(n){
                ans.push_back(x);
                ans.push_back(-1*x);
                x++;
                n -= 2;
            }
        }

        return ans;
    }
};