class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodeCount, int &edgeCount){

        vis[node] = 1;
        nodeCount++;

        for(auto &it: adj[node]){
            edgeCount++;
            if(!vis[it])
            dfs(it, adj, vis, nodeCount, edgeCount);           
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i<n; i++){

            int nodeCount = 0;
            int edgeCount = 0;

            if(!vis[i]) {

                dfs(i, adj, vis, nodeCount, edgeCount);
                if(edgeCount/2 == (nodeCount * (nodeCount-1))/2)
                count++;
            }
        }

        return count;
    }
};