class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt  = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==maxi) cnt++;
            else cnt =0;
            ans = max(ans, cnt );
        }
        return ans;
    }
};