class Solution {
public:

    int memo(vector<int> &v, int i, int prev, vector<vector<int>> &dp){

        if(i == v.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0, skip = 0;;
        if(prev ==-1 || v[i]>v[prev])
        take = 1 + memo(v, i+1, i, dp);
        skip = memo(v, i+1, prev, dp);

        return dp[i][prev+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
        return memo(nums, 0, -1, dp);
    }
};