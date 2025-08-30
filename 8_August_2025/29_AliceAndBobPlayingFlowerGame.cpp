class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd1 = (n+1)/2;
        int even1 = n - odd1;
        int odd2 = (m+1)/2;
        int even2 = m - odd2;

        long long ans = (1ll * odd1 * even2) + (1ll * odd2 * even1);
        return ans;
    }
};