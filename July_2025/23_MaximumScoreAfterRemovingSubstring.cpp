class Solution {
    int removeAB(string& s, int& x, vector<int>& vis){
        int cnt = 0, ans = 0;
        vector<int> v;
        for(int i=0; i<s.length(); i++){
            if(vis[i])  continue;
            else if(s[i]=='a')  {
                v.push_back(i);
            }
            else if(s[i]=='b'){
                if(v.size() > 0){
                    ans += x;
                    vis[i] = 1;
                    vis[v.back()] = 1;
                    v.pop_back();
                }
            }
            else  v.clear();
        }

        return ans;
    }

    int removeBA(string& s, int& x, vector<int>& vis){
        int cnt = 0, ans = 0;
        vector<int> v;
        for(int i=0; i<s.length(); i++){
            if(vis[i])  continue;
            else if(s[i]=='b')  {
                v.push_back(i);
            }
            else if(s[i]=='a'){
                if(v.size() > 0){
                    ans += x;
                    vis[i] = 1;
                    vis[v.back()] = 1;
                    v.pop_back();
                }
            }
            else  v.clear();
        }

        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        vector<int> vis(n, 0);
        int ans = 0;

        if(x > y){
            ans += removeAB(s, x, vis);
            ans += removeBA(s, y, vis);
        }
        else{
            ans += removeBA(s, y, vis);
            ans += removeAB(s, x, vis);
        }

        return ans;
    }
};