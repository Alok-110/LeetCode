class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){

        vis[node] = 1;
        for(auto &it: adj[node]){
            if(!vis[it])
            dfs(it, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> adj(n+1);
        int ans = 1e9;
        for(auto &it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n+1, 0);
        dfs(1, adj, vis);

        for(auto &it: roads){

            if(vis[it[0]])
            ans = min(ans, it[2]);
        }
        return ans;
    }
};