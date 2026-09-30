class Solution {
public:

    int memo(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){

        int m = word1.size();
        int n = word2.size();

        if(i == m) return n-j;
        if(j == n) return m-i;

        if(dp[i][j] != -1) return dp[i][j];

        int insert = 1e9, replace = 1e9, deletion = 1e9, equal = 1e9;

        if(word1[i] == word2[j])
        equal = memo(word1, word2, i+1, j+1, dp);

        else{

            insert = 1 + memo(word1, word2, i, j+1, dp);
            deletion = 1 + memo(word1, word2, i+1, j, dp);
            replace = 1 + memo(word1, word2, i+1, j+1, dp);
        }

        return dp[i][j] = min(insert, min(deletion, min(replace, equal)));

    }

    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memo(word1, word2, 0, 0, dp);
    }
};