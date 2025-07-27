class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>inc(n,0);
        vector<int>dec(n,0);
        dec[0]=0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>=nums[i]) dec[i] = dec[i-1]+1;
            else dec[i]=0;
        }
        inc[n-1]=0;
        for(int i=n-2; i>=0; i--){
            if(nums[i+1]>=nums[i]) inc[i] = inc[i+1]+1;
            else inc[i]=0;
        }
        vector<int>ans;
        for(int i=k; i<n-k; i++){
            if(inc[i+1]+1>=k && dec[i-1]+1>=k) ans.push_back(i);
        }
        return ans;
    }
};