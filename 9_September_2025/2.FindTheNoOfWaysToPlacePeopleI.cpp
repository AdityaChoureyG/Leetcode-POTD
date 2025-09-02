#define pdi pair<double, int>

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdi> pq;
        int n = classes.size();
        double ans = 0;


        for(int i=0; i<n; i++){
            pq.push({((classes[i][0]+1)*1.0)/(classes[i][1]+1) - (classes[i][0]*1.0)/classes[i][1], i});
        }

        while(extraStudents--){
            auto cur = pq.top();
            int i = cur.second;
            // cout<<i<<endl;
            pq.pop();
            classes[i][0] += 1;
            classes[i][1] += 1;
            pq.push({((classes[i][0]+1)*1.0)/(classes[i][1]+1) - (classes[i][0]*1.0)/classes[i][1], i});
        }

        for(int i=0; i<n; i++){
            ans += ((classes[i][0]*1.0)/classes[i][1]);
        }

        return ans/n;
        
    }
};