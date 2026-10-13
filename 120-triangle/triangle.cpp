class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));

        for(int j = 0; j<triangle.size(); j++){

            dp[triangle.size()-1][j] = triangle[triangle.size()-1][j];
        }

        for(int i = triangle.size()-2; i>=0; i--){

            for(int j = 0; j<=i; j++){

                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};