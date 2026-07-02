class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>> adj(n);
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(2, 0));

        for(auto &it: redEdges)
        adj[it[0]].push_back({it[1], 1});

        for(auto &it: blueEdges)
        adj[it[0]].push_back({it[1], 0});

        q.emplace(0,-1);

        vector<int> dist(n, -1);
        int distance = 0;

        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                auto[node, color] = q.front();
                q.pop();

                if(dist[node] == -1)
                dist[node] = distance;

                for(auto &it: adj[node]){

                    if(!vis[it.first][it.second]){

                        if(it.second != color){

                            q.emplace(it.first,it.second);
                            vis[it.first][it.second] = 1;
                        }   
                    }
                }
            }
            distance++;
        }
        return dist;
    }
};