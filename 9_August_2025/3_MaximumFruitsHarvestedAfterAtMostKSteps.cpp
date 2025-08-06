class Solution {
    int firstSmall(vector<int>& arr, int pvt){
        int lo = 0, hi = arr.size()-1;

        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] > pvt)  hi = mid - 1;
            else    lo = mid + 1;
        }

        return hi;
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        vector<int> left, leftPro, right, rightPro;

        for(auto it : fruits){
            if(it[0] < startPos){
                left.push_back(startPos - it[0]);
                leftPro.push_back(it[1]);
            }
            else{
                right.push_back(it[0] - startPos);
                rightPro.push_back(it[1]);
            }
        }
        reverse(left.begin(), left.end());
        reverse(leftPro.begin(), leftPro.end());

        for(int i=1; i<leftPro.size(); i++){
            leftPro[i] += leftPro[i-1];
        }

        for(int i=1; i<rightPro.size(); i++){
            rightPro[i] += rightPro[i-1];
        }

        int mxpro = 0, pro = 0;

        for(int i=0; i<right.size(); i++){
            pro = 0;
            if(right[i] <= k){
                pro = rightPro[i];
                int rem = k - (2*right[i]);
                if(rem > 0){
                    int lb = firstSmall(left, rem);
                    if(lb != -1)  pro += leftPro[lb];
                }
                mxpro = max(mxpro, pro);
            }
            else  break;
        }

        for(int i=0; i<left.size(); i++){
            pro = 0;
            if(left[i] <= k){
                pro = leftPro[i];
                int rem = k - (2*left[i]);
                if(rem > 0){
                    int lb = firstSmall(right, rem);
                    if(lb != -1)  pro += rightPro[lb];
                }
                mxpro = max(mxpro, pro);
            }
            else  break;
        }
        

        return mxpro;
    }
};