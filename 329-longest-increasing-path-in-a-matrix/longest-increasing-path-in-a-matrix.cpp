class Solution {
public:

    int memo(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){

        int n = grid.size();
        int m = grid[0].size();

        // if(i < 0 || i == n || j<0 || j==m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int right = 1, left = 1, down = 1, up = 1;
        if(j+1 < m && grid[i][j+1] > grid[i][j])
        right = 1 + memo(grid, i, j+1, dp);

        if(j-1 >= 0 && grid[i][j-1] > grid[i][j])
        left = 1 + memo(grid, i, j-1, dp);

        if(i+1 < n && grid[i+1][j] > grid[i][j])
        down = 1 + memo(grid, i+1, j, dp);

        if(i-1 >= 0 && grid[i-1][j] > grid[i][j])
        up = 1 + memo(grid, i-1, j, dp);

        return dp[i][j] = max({up, left, down, right});
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