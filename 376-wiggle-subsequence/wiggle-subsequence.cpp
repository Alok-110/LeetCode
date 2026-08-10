class Solution {
public:

    int memo(auto &nums, int i, int prevState, int prevIdx, auto &dp){

        if(i==nums.size()) return 0;

        if(dp[i][prevIdx+1][prevState+1] != -1)
        return dp[i][prevIdx+1][prevState+1];

        int take = 0, skip = 0;

        int currState = -1;
        if (prevIdx != -1)
        currState = nums[i] > nums[prevIdx] ? 1 : 0;

        if (prevIdx == -1 || (nums[i] != nums[prevIdx] && prevState != currState))
        take = 1 + memo(nums, i+1, currState, i, dp);

        skip = memo(nums, i+1, prevState, prevIdx, dp);

        return dp[i][prevIdx+1][prevState+1] = max(take,skip);
    }

    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n+1, vector<int> (3, -1)));

        return memo(nums, 0, -1, -1, dp);
    }
};