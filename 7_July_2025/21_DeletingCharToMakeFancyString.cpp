#include<bits/stdc++.h>

class Solution {
public:
    string makeFancyString(string s) {
        char prevch = '3';
        int cnt = 0;
        string ans;

        for(int i=0; i<s.length(); i++){
            if(s[i] == prevch){
                cnt++;
            }
            else{
                prevch = s[i];
                cnt = 1;
            }
            if(cnt<3)  ans += s[i];
        }

        return ans;
    }
};