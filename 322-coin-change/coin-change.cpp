class Solution {
public:

    int memo(auto &coins, int i, int amount, auto &dp){

        if(amount == 0) return 0;
        if(amount < 0 || i==coins.size()) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 0, skip = 0;
        take = 1 + memo(coins, i, amount-coins[i], dp);
        skip = memo(coins, i+1, amount, dp);

        return dp[i][amount] = min(take, skip); 
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = memo(coins, 0, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};