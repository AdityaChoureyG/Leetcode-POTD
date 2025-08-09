class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, result, cur;
        prev.insert(arr[0]);

        for(int i=0; i<arr.size(); i++){
            for(auto it : prev){
                cur.insert(it|arr[i]);
                result.insert(it|arr[i]);
            }
            cur.insert(arr[i]);
            result.insert(arr[i]);
            prev = cur;
            cur.clear();
        }

        return result.size();
    }
};