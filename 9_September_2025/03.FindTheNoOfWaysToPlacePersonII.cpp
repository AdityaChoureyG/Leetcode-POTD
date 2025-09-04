#define pi pair<int, int>

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        
        // for(auto it : points) cout<<it[0]<<' '<<it[1]<<endl;
        int cnt = 0 , n = points.size();

        for(int i=1; i<n; i++){
            int b = points[i][1];
            int y = 1e9 + 1;
            for(int j=i-1; j>=0; j--){
                int d = points[j][1];
                if(d >= b){
                    if(d < y){
                        y = d;
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};