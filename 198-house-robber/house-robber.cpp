class Solution {
public:

    int memo(auto &nums, int i, auto &dp){

        int take = 0, skip = 0;
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        take = nums[i] + memo(nums, i+2, dp);
        skip = memo(nums, i+1, dp);



        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        int take = 0, skip = 0;
        return memo(nums, 0, dp);
    }
};