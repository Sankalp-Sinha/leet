class Solution {
public:

   bool check(int mid, string s, vector<int>& order, int k) {
    for (int i = 0; i <= mid; ++i)
        s[order[i]] = '*';

    long long totalSubstrings = 1LL * s.size() * (s.size() + 1) / 2;
    long long nonStarSubstrings = 0;
    int count = 0;

    for (char c : s) {
        if (c != '*') {
            count++;
        } else {
            nonStarSubstrings += 1LL * count * (count + 1) / 2;
            count = 0;
        }
    }

    // Don't forget the last segment if it ended without '*'
    nonStarSubstrings += 1LL * count * (count + 1) / 2;

    long long validSubstrings = totalSubstrings - nonStarSubstrings;
    return validSubstrings >= k;
}

int minTime(string s, vector<int>& order, int k) {
    int low = 0, high = s.size()-1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid, s, order, k)) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    return ans;
}

};