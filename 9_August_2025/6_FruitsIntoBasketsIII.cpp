class SegmentTree{
    vector<int> v;
    int n;
public:
    SegmentTree(int n, vector<int>& baskets){
        v.resize(4*n, 0);
        this->n = n;
        buildTree(0, n-1, 0, baskets);
        // for(auto it : v)  cout<<it<<' ';
    }

    void buildTree(int lo, int hi, int i, vector<int>& bas){
        if(lo==hi){
            v[i] = bas[lo];
            return;
        }

        int mid = lo + (hi - lo)/2;
        buildTree(lo, mid, 2*i+1, bas);
        buildTree(mid+1, hi, 2*i+2, bas);

        v[i] = max(v[2*i+1], v[2*i+2]);
    }

    void updateTree(int i, int lo, int hi, int idx){
        if(lo==hi){
            v[i] = INT_MIN;
            return;
        }
        int mid = lo + (hi-lo)/2;
        if(idx<=mid){
            // go left
            updateTree(2*i+1, lo, mid, idx);
        }
        else{
            // go right
            updateTree(2*i+2, mid+1, hi, idx);
        }

        v[i] = max(v[2*i+1], v[2*i+2]);
    }

    bool getres(int i, int lo, int hi, int fruit){
        int mid = lo + (hi - lo)/2;
        
        if(fruit <= v[i]){
            // fruit can be fix in b/w 0---n-1
            if(lo==hi){
                // we have reached the index so occupy this and update max
                // updateTree(0, 0, n-1, lo);
                v[i] = -1;
                return 1;
            }
            if(v[2*i+1] >= fruit){
                // can fix in left part
                if(getres(2*i+1, lo, mid, fruit)){
                    v[i] = max(v[2*i+1], v[2*i+2]);
                    return 1;
                }
            }
            else  {
                if(getres(2*i+2, mid+1, hi, fruit)){
                    v[i] = max(v[2*i+1], v[2*i+2]);
                    return 1;
                }
            }
        }
        return 0;
    }

    void print(){
        for(auto it : v)   cout<<it<<' ';
        cout<<endl;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree st(n, baskets);
        int cnt = 0;

        for(auto it : fruits){
            if(st.getres(0, 0, n-1, it)) cnt++;
            st.print();
        }

        return n-cnt;
    }
};