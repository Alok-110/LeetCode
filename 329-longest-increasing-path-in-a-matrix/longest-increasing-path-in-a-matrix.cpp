class Solution {
public:

    int memo(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){

        int n = grid.size();
        int m = grid[0].size();

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1;

        for(int k = 0; k<4; k++){

            int x = i + r[k];
            int y = j + c[k];

            if(x>=0 && x<n && y>=0 && y<m && grid[x][y] > grid[i][j])
            ans = max(ans, 1 + memo(grid, x, y, dp));
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        int path = 0;
        for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){

            path = max(path, memo(matrix, i, j, dp));
        }
        return path;
    }
};