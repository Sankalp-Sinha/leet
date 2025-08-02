class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<long long int,long long int>mp;
        unordered_map<long long int,long long int>mp1;
        unordered_map<long long int,long long int>mp2;
        for(int i=0; i<n; i++){   
            mp[basket1[i]]++;
            mp[basket2[i]]++; 
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
        }
        long long int min_num = LLONG_MAX;
        for(auto &[x,y] : mp){
            if(y&1) return -1;
            min_num = min(min_num, x);
        }


        long long int ans = 0;
        vector<long long int>v1;
        vector<long long int>v2;

        for(auto &[x,y]: mp){
            if(mp1[x]>mp2[x]){
                for(int i=1; i<=(mp1[x] - (mp[x]/2)); i++) v1.push_back(x);
            }
            else if(mp1[x]<mp2[x]) {
                for(int i=1; i<=(mp2[x] - (mp[x]/2)); i++) v2.push_back(x);
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int i=0; 
        int j=v2.size()-1;


        while(i<v1.size() && j>=0){
            ans = ans + min(min(v1[i], v2[j]), min_num*2);
            i++;
            j--;
        }

        return ans;
    }
};