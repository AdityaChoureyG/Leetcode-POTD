class Solution {
public:
    string largestGoodInteger(string num) {
        char prev='a', ans = 'a';
        string st = "";
        int cnt = 0;

        for(int i=0; i<num.length(); i++){
            if(num[i] == prev){
                cnt++;
                if(cnt >= 3){
                    if(ans=='a' || (ans-'0') < (prev-'0')){
                        ans = num[i];
                    }
                }
            }
            else{
                cnt = 1;
                prev = num[i];
            }
        }

        if(ans == 'a')   return "";
        for(int i=0; i<3; i++)   st += ans;

        return st;
    }
};