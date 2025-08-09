class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0, n=fruits.size();
        int freq[100002] = {0};
        int cnt = 0;
        int ans = 0;

        while(j<n){
            if(freq[fruits[j]]==0) cnt++;
            freq[fruits[j]]++;
            if(cnt > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0)  cnt--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};