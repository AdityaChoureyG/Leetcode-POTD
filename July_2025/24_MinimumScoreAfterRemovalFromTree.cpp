class Solution {
    int t = 0;
    int dfs(int node, int par, vector<int>& nums, vector<vector<int>>& adj, vector<int>& intime, vector<int>& outtime, vector<int>& subxor){
        t++;
        intime[node] = t;
        // cout<<node<<endl;

        int xo = nums[node];
        for(auto it: adj[node]){
            if(it != par){
                xo ^= dfs(it, node, nums, adj, intime, outtime, subxor);
            }
        }

        t++;
        outtime[node] = t;
        return subxor[node] = xo;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        vector<int> intime(n), outtime(n), subxor(n);
        for(auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int x = dfs(0, -1, nums, adj, intime, outtime, subxor);
        int ans = INT_MAX;

        // for(int i=0; i<n; i++)  cout<<i<<' ';
        // cout<<endl;
        // for(auto it : intime)  cout<<it<<' ';
        // cout<<endl;
        // for(auto it : outtime)  cout<<it<<' ';
        // cout<<endl;
        // for(auto it : subxor)  cout<<it<<' ';
        // cout<<endl;

        for(int i=1; i<n-1; i++){
            int compA, compB, compC;
            for(int j=i+1; j<n; j++){
                // taking i and j subtree as two separate comp
                if(intime[i]<intime[j] && outtime[j]<outtime[i]){
                    // j is inside i
                    compA = subxor[0] ^ subxor[i];
                    compB = subxor[j];
                    compC = subxor[i] ^ compB;

                }
                else if(intime[j]<intime[i] && outtime[i]<outtime[j]){
                    // i is inside j
                    compA = subxor[0] ^ subxor[j];
                    compB = subxor[i];
                    compC = subxor[j] ^ compB;
                }
                else{
                    // both are individual
                    compA = subxor[0] ^ subxor[i] ^ subxor[j];
                    compB = subxor[j];
                    compC = subxor[i];

                }

                ans = min(ans, max(compA, max(compB, compC))-min(compA, min(compB, compC)));
            }
        }
        
        return ans;
    }
};