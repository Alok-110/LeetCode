class Solution {
public:

    int memo(string &s, string &t, int i, int j, vector<vector<int>> &dp){

        if(i==s.size() || j==t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int match = 0, skip1 = 0, skip2 = 0;

        if(s[i] == t[j])
        match = 1 + memo(s, t, i+1, j+1, dp);
        skip1 = memo(s, t, i, j+1, dp);
        skip2 = memo(s, t, i+1, j, dp);

        return dp[i][j] = max({match, skip1, skip2});
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        return memo(text1, text2, 0, 0, dp);
    }
};