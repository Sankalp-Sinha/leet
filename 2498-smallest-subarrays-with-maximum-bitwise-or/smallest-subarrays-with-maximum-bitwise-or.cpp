class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>pos(31,-1);
        for(int i=n-1; i>=0; i--){
            int r = i;
            for(int j=0; j<31; j++){
                if(!(nums[i]&(1<<j))){
                    if(pos[j]!=-1){
                        r=max(r,pos[j]);
                    }
                }
                else pos[j]=i;
            }
            ans[i]=r-i+1;
        }
        return ans;
    }
};