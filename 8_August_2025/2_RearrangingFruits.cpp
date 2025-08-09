class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp, mp1, mp2;
        vector<int> v1, v2;
        long long cost = 0;
        int minele = INT_MAX;

        for(auto it : basket1){
            mp[it]++;
            mp1[it]++;
            minele = min(minele, it);
        }

        for(auto it : basket2){
            mp[it]++;
            mp2[it]++;
            minele = min(minele, it);
        }

        for(auto it : mp){
            if(it.second&1)  return -1;
        }

        for(auto it : mp1){
            int extra = mp[it.first] - (2 * mp2[it.first]);
            extra /= 2;
            while(extra>0){
                v1.push_back(it.first);
                extra--;
            }
        }

        for(auto it : mp2){
            int extra = mp[it.first] - (2 * mp1[it.first]);
            extra /= 2;
            while(extra>0){
                v1.push_back(it.first);
                extra--;
            }
        }

        sort(v1.begin(), v1.end());

        int i=0, j=v1.size()-1;

        while(i<j){
            cost += min(min(v1[i], v1[j]), 2*minele);
            i++;
            j--;
        }
        
        return cost;
    }
};