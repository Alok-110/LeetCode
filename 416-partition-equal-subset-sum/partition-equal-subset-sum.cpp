class Solution {
public:

    int memo(vector<int> &v, int i, int target, vector<vector<int>> &dp){

        if(i == v.size() || target<0)
        return 0;
        if(target == 0) return 1;

        if(dp[i][target] != -1) return dp[i][target];

        int take = 0, skip = 0;
        take = memo(v, i+1, target-v[i], dp);
        skip = memo(v, i+1, target, dp);

        return dp[i][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(auto &it: nums)
        sum += it;
        vector<vector<int>> dp(n, vector<int> (sum, -1));

        if(sum & 1) return false;
        return memo(nums, 0, sum/2, dp);
    }
};