class Solution {
public:
    int f(vector<int>&nums, int ind, int currOr, int target){
        if(ind==nums.size()){
            if(currOr == target) return 1;
            else return 0;
        }
        int pick = f(nums, ind+1, currOr | nums[ind], target);
        int not_pick = f(nums, ind+1, currOr, target);
        return pick + not_pick;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int orr = 0;
        for(auto &x : nums) orr= orr | x;
        return f(nums, 0, 0, orr);
    }
};