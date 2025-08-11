class Solution {
    bool f(int n, vector<int>& freq){
        vector<int> freq1(10, 0);
        string sn = to_string(n);

        for(int i=0; i<sn.size(); i++)   freq1[sn[i]-'0']++;

        for(int i=0; i<10; i++){
            if(freq[i]!=freq1[i])   return 0;
        }

        return 1;
    }
public:
    bool reorderedPowerOf2(int n) {
        if(n==1)   return 1;
        vector<int> freq(10, 0);
        string sn = to_string(n);
        // cout<<sn;
        for(int i=0; i<sn.size(); i++) {
            freq[sn[i]-'0']++;
        }

        for(int i=1; i<30; i++){
            // cout<<(2<<i)<<endl;
            if(f(2<<i, freq))  return 1;
        }

        return 0;
    }
};