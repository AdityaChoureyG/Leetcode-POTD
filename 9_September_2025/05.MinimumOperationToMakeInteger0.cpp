class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int k=1; k<=60; k++){
            long long x = num1 - (1ll * k * num2);
            if(x < k)  return -1;
            if(__builtin_popcountll(x) <= k)  return k;
        }

        return -1;
    }
};