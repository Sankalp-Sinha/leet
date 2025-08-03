class Solution {
public:
    bool isSubsequence(string p, string s, vector<bool>&removed) {
        int i = 0;
        for(int j = 0; j<s.size(); j++){
            if(i<p.size() && removed[j]==false && s[j]==p[i] ) {
                i++;
            }
        }
        return i==p.size();
    }

    bool check(int k, string s, string p, vector<int>& removable) {
        vector<bool>removed(s.size(), false);
        for (int i = 0; i < k; i++) {
            removed[removable[i]]=true;
        }
        return isSubsequence(p,s,removed);
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0;
        int high = removable.size();
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, s, p, removable)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};