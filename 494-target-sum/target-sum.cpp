class Solution {
public:
    int sum(vector<int>& v, int target, int i, auto &dp, int offset) {

        if(i == v.size())
        return target == 0;

        if(target < -offset || target > offset)
        return 0;

        if(dp[i][target + offset] != -1)
            return dp[i][target + offset];

        int pos = sum(v, target - v[i], i + 1, dp, offset);
        int neg = sum(v, target + v[i], i + 1, dp, offset);

        return dp[i][target + offset] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int offset = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > offset)
        return 0;

        vector<vector<int>> dp( nums.size(), vector<int>(2 * offset + 1, -1));

        return sum(nums, target, 0, dp, offset);
    }
};