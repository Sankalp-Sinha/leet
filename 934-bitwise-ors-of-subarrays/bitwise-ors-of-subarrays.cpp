class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int>s;
        set<int>temp;
        for(int i=0; i<n; i++){
            set<int>temp2;
            temp2.insert(arr[i]);
            for(auto &x:temp) temp2.insert(arr[i] | x);
            temp = temp2;
            for(auto &x:temp2) s.insert(x);
        }
        return s.size();

    }
};