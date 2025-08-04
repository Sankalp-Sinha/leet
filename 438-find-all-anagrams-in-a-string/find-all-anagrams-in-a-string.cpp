class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>s_count(26,0);
        vector<int>p_count(26,0);
        vector<int>ans;
        if (s.size() < p.size()) return ans;

        for(auto x: p) p_count[x - 'a']++;
        int window = p.size();
        for(int i = 0; i<window; i++){
            s_count[s[i]-'a']++;
        }
        if(p_count == s_count) ans.push_back(0);

        int left = 0;

        for(int i = window; i<s.size(); i++){
            s_count[s[i]-'a']++;
            s_count[s[i-window]-'a']--;
            if(s_count == p_count) ans.push_back(i-window+1);
        }

        return ans;

    }
};