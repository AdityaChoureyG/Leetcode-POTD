class Solution {
    bool check(int x){
        // string st = to_string(x);

        // for(int i=0; i<st.length(); i++){
        //     if(st[i] == '0') return 0;
        // }

        int cnt = 0;
        
        while(x){
            if(x%10 == 0) cnt++;
            x /= 10;
        }

        return cnt==0 ? 1 : 0;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int a=1; a<n; a++){
            int b = n - a;
            if(check(a) && check(b)){
                return {a, b};
            }
        }

        return {};
    }
};