class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0 && (!(n&n-1)))  {
            if(__builtin_popcount(n-1)&1)  return 0;
            return 1;
        }
        return 0;
    }
};