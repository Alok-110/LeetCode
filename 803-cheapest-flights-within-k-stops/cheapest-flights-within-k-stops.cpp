class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : flights) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v, cost});
        }
        queue<pair<int, int>> q;
        vector<int> dist(n, 1e9);
        q.push({src, 0});
        dist[src] = 0;

        while (!q.empty() && k>=0) {

            int size = q.size();
            while (size--) {

                auto[node, currCost] = q.front();
                q.pop();

                for (auto it : adj[node]) {

                    int nbr = it.first;
                    int edgeWeight = it.second;

                    if (currCost + edgeWeight < dist[nbr]) {
                        dist[nbr] = currCost + edgeWeight;
                        q.push({nbr, currCost + edgeWeight});
                    }
                }
            }
            k--;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};