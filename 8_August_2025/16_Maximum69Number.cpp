class Solution {
public:
    int maximum69Number (int num) {
        string sn = to_string(num);

        for(int i=0; i<sn.length(); i++){
            if(sn[i] == '6'){
                sn[i] = '9';
                break;
            }
        }

        return stoi(sn);
    }
};