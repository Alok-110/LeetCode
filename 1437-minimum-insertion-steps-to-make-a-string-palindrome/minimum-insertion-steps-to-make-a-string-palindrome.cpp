class Solution {
public:

    int memo(auto &s, auto &t, int i, int j, auto &dp){

        if(i==s.size() || j==s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int match = 0, skip1 = 0, skip2 = 0;
        if(s[i]==t[j])
        match = 1 + memo(s, t, i+1, j+1, dp);

        skip1 = memo(s, t, i+1, j, dp);
        skip2 = memo(s, t, i, j+1, dp);

        return dp[i][j] = max({match, skip1, skip2});
    }

    int minInsertions(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        string t = s;
        reverse(t.begin(), t.end());
        int lps = memo(s, t, 0, 0, dp);
        return s.size()-lps;
    }
};