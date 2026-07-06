class Solution {
public:

    int memo(string &s, string &t, int i, int j, vector<vector<int>> &dp){

        if(i == s.size() || j == t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0, skip1 = 0, skip2 = 0;
        if(s[i] == t[j])
        take = 1 + memo(s, t, i+1, j+1, dp);
        skip1 = memo(s, t, i+1, j, dp);
        skip2 = memo(s, t, i, j+1, dp);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int longestPalindromeSubseq(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size(), vector<int> (t.size(), -1));
        return memo(s, t, 0, 0, dp);
    }
};