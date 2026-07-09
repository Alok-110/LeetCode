class Solution {
public:

    int memo(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp){

        if(i == nums1.size() || j == nums2.size()) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int take = -1e9, skip1 = -1e9, skip2 = -1e9;
        take = max(nums1[i]*nums2[j], nums1[i]*nums2[j] + memo(nums1, nums2, i+1, j+1, dp));
        skip1 = memo(nums1, nums2, i, j+1, dp);
        skip2 = memo(nums1, nums2, i+1, j, dp);

        return dp[i][j] = max({take, skip1, skip2});

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size(), -1));
        return memo(nums1, nums2, 0, 0, dp);
    }
};