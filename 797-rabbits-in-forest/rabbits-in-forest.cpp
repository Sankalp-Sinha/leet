class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans = 0;
        for(auto &x : answers) m[x]++;
        for(auto &[x,y]: m){
            int k = x+1;
            y--;
            int kk = (y/k)+1;
            ans=ans+kk*(k);
        }
        return ans;
    }
};