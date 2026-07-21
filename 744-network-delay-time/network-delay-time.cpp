class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1, 1e9);

        for(auto &it: times)
        adj[it[0]].push_back({it[1], it[2]});
        
        pq.emplace(0,k);
        dist[k] = 0;

        while(!pq.empty()){

            auto[currDist, node] = pq.top();
            pq.pop();

            for(auto &it: adj[node]){

                int newDist = currDist + it.second;
                if(newDist < dist[it.first]){

                    dist[it.first] = newDist;
                    pq.emplace(newDist, it.first);
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++)
        maxi = max(maxi, dist[i]);

        return maxi == 1e9 ? -1 : maxi;
    }
};