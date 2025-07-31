class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>s;
        unordered_set<int>temp;
        for(int i=0; i<n; i++){
            unordered_set<int>temp2;
            temp2.insert(arr[i]);
            for(auto &x:temp) temp2.insert(arr[i] | x);
            temp = temp2;
            for(auto &x:temp2) s.insert(x);
        }
        return s.size();

    }
};