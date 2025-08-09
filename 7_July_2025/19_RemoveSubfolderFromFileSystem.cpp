class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        int n = folder.size();
        vector<string> ans;
        sort(folder.begin(), folder.end());

        for(int i=0; i<n; i++){
            string temp = "/";
            bool flag = true;
            for(int j=1; j<folder[i].size(); ){
                while(j<folder[i].size() && folder[i][j]!='/'){
                    temp += folder[i][j];
                    j++;
                }
                if(st.find(temp) != st.end()){
                    flag = false;
                    break;
                }
                temp += '/';
                j++;
            }
            if(flag)   st.insert(folder[i]);
        }

        for(auto it : st)   ans.push_back(it);

        return ans;
    }
};