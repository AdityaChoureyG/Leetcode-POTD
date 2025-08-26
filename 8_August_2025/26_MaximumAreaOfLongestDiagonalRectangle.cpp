class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float mxdia = 0;
        int mxarea = 0;

        for(auto it : dimensions){
            int w=it[0], l=it[1];
            float d = sqrt(w*w + l*l);
            // cout<<d<<' '<<w*l<<endl;
            if(mxdia < d){
                mxdia = d;
                mxarea = w * l;
            }
            else if(mxdia == d){
                if(mxarea < w*l)   mxarea = w*l;
            }
        }

        return mxarea;
    }
};