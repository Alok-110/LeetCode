class Solution {
public:

    bool memo(auto &s, auto &p, int i, int j, auto &dp){

        if(i==s.size() && j==p.size()) return true;
        if(i==s.size()){

            for(int k=j; k<p.size(); k++)
            if(p[k] != '*') return false;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool match = false, match2 = false, match3 = false, skip = false;
        if(s[i] == p[j] || p[j]=='?')
        match = match || memo(s, p, i+1, j+1, dp);

        if(p[j] == '*'){

            match2 = match2 || memo(s, p, i+1, j, dp);
            match3 = match3 || memo(s, p, i+1, j+1, dp);
            skip = skip || memo(s, p, i, j+1, dp);
        }

        return dp[i][j] = match || match2 || match3 || skip;
    }

    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));
        return memo(s, p, 0, 0, dp);
    }
};

