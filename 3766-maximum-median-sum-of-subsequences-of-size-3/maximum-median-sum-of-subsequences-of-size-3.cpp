class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        sort(nums.begin(), nums.end());
        int c = 0;
        long long int ans = 0;
        long long int i = n-2;
        while(c!=k){
            ans = ans + nums[i];
            i = i-2;
            c++;
        }
        return ans;
    }
};