class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diffa = abs(x-z);
        int diffb = abs(y-z);

        if(diffa < diffb)   return 1;
        else if(diffa > diffb)   return 2;
        return 0;
    }
};