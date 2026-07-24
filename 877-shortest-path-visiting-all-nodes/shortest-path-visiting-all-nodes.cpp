class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int> (1<<n, -1));
        for(int i=0; i<n; i++){
            q.emplace(i, 1<<i);
            dist[i][1<<i] = 0;
        }

        int distance = 1;
        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                auto[node, mask] = q.front();
                q.pop();

                for(auto &it: graph[node]){

                    int newMask = mask | (1<<it);
                    
                    if(dist[it][newMask] == -1){
                        dist[it][newMask] = distance;
                        q.emplace(it, newMask);
                    }
                }
            }
            distance++;
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++)
            if(dist[i][(1<<n)-1] != -1)
                ans = min(ans, dist[i][(1<<n)-1]);
        return ans;
    }
};