class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> pref_L(n, 0);
        vector<long long> suffix_T(n, 0);
        for(int i = 0; i <n; i++){
           if(i) pref_L[i] = pref_L[i-1];
           if(s[i]=='L') pref_L[i]++;
        }

        for(int i = n-1; i>=0; i--){
           if(i!=(n-1)) suffix_T[i] = suffix_T[i+1];
           if(s[i]=='T') suffix_T[i]++;
        }

        long long ans_L = 0;
        long long ans_T = 0;
        long long ans_C = 0;
        long long int  best = 0;

        for(int i = 0; i < n; i++){
            if(s[i]=='C') ans_C = ans_C + (pref_L[i]) * (suffix_T[i]);
            if(s[i]=='C') ans_L = ans_L + (pref_L[i]+1)*(suffix_T[i]);
            if(s[i]=='C') ans_T = ans_T + (pref_L[i]) * (suffix_T[i]+1);
            best = max(best , pref_L[i]*suffix_T[i]);
        }

        return max({ans_C+best, ans_L, ans_T});
    }
};