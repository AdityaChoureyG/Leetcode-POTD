class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for(auto it : fruits){
            for(int i=0; i<n; i++){
                if(!vis[i] && baskets[i]>=it){
                    vis[i] = 1;
                    cnt++;
                    break;
                }
            }
        }

        return n-cnt;
        
    }
};