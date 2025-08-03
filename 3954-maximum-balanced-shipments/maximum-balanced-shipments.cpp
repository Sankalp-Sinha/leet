class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int maxi = weight[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            if(weight[i]>=maxi) maxi = weight[i];
            else {
                ans++;
                maxi = INT_MIN;
            }
        }
        return ans;
    }
};