class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> topo;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> indeg(n, 0);

        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }

        for(int i = 0; i < n; i++)
        if(indeg[i] == 0){
            q.push(i);
            topo.push_back(i);
            dp[i][colors[i]-'a'] = 1;
        } 

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it: adj[node]){
                for(int c = 0; c < 26; c++)
                    dp[it][c] = max(dp[it][c], dp[node][c] + (colors[it]-'a' == c ? 1 : 0));

                indeg[it]--;
                if(indeg[it] == 0){
                    topo.push_back(it);
                    q.push(it);
                    dp[it][colors[it]-'a'] = max(dp[it][colors[it]-'a'], 1);
                }
            }
        }

        if(topo.size() != n) return -1;

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int c = 0; c < 26; c++)
                ans = max(ans, dp[i][c]);
        return ans;
    }
};