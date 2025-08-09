#include<bits/stdc++.h>

class Solution {
public:
    bool isValid(string word) {
        int cntv = 0, cntc = 0, n = word.length();

        if(n<3)   return 0;

        for(auto ch : word){
            if(ch=='@' || ch=='#' || ch=='$')
                return false;
            else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U')
                    cntv++;
                else    cntc++;
            }
        }

        return (cntv>0 && cntc>0)? 1 : 0;
        
    }
};