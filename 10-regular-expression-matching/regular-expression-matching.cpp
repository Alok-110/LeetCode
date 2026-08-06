class Solution {
public:

    bool memo(auto &s, auto &p, int i, int j, auto &dp){

        if(i==s.size() && j==p.size()) return true;
        if(j >= p.size()) return false;
        if(i==s.size()){

            if(p[p.size()-1] != '*') return false;
            for(int k=j+1; k<p.size()-1; k+=2)
            if(p[k] != '*') return false;

            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool match1 = false, match2 = false, skip = false;

        if((s[i]==p[j] || p[j] == '.') && p[j+1] != '*')
        match1 = match1 || memo(s, p, i+1, j+1, dp);

        if((s[i]==p[j] || p[j] == '.') && p[j+1] == '*')
        match2 = match2 || memo(s, p, i+1, j, dp);

        if(p[j+1] == '*')
        skip = skip || memo(s, p, i, j+2, dp);

        return dp[i][j] = match1 || match2 || skip;
    }

    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));
        return memo(s, p, 0, 0, dp);
    }
};