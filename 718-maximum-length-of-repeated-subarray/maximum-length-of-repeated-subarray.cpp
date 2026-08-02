class Solution {
public:

    int memo(auto &nums1, auto &nums2, int i, int j, auto &dp){

        if(i==nums1.size() || j==nums2.size()) return 0;
        if(nums1[i] != nums2[j]) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int match=0;
        if(nums1[i] == nums2[j])
        match = max(match, 1 + memo(nums1, nums2, i+1, j+1, dp));

        return dp[i][j] = match;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++)
        for(int j = 0; j < nums2.size(); j++)
        ans = max(ans, memo(nums1, nums2, i, j, dp));
        return ans;
    }
};