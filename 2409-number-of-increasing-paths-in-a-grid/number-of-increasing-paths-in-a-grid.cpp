class Solution {
public:

    const int MOD = 1000000007;

    int memo(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){

        int n = grid.size();
        int m = grid[0].size();

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        if(dp[i][j] != -1)
            return dp[i][j];

        long long ans = 1;

        for(int k = 0; k < 4; k++){

            int x = i + r[k];
            int y = j + c[k];

            if(x >= 0 && x < n && y >= 0 && y < m &&
            grid[x][y] > grid[i][j]){

                ans = (ans + memo(grid, x, y, dp)) % MOD;
            }
        }

        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        long long ans = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        ans = (ans + memo(grid, i, j, dp)) % MOD;
    
        return ans;
    }
};