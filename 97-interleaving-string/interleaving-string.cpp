class Solution {
public:

    bool memo(auto &s, auto &t, auto &ans, int i, int j, auto &dp){

        if(i+j == ans.size()) return true;
        if(s[i] != ans[i+j] && t[j] != ans[i+j]) return false;

        if(dp[i][j] != -1) return dp[i][j];

        int match1 = false, match2 = false;
        if(s[i] == ans[i+j])
        match1 = match1 || memo(s, t, ans, i+1, j, dp);

        if(t[j] == ans[i+j])
        match2 = match2 || memo(s, t, ans, i, j+1, dp);

        return dp[i][j] = match1 || match2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        return memo(s1, s2, s3, 0, 0, dp);
    }
};