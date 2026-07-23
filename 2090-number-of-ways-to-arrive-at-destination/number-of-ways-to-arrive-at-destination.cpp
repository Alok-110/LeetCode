class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        using LL = long long;
        using P = pair<LL,LL>;
        int MOD = 1000000007;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<P>> adj(n);
        vector<LL> time(n, 1e18);
        vector<LL> ways(n, 0);

        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        pq.push({0,0});
        time[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){

            auto[currTime, node] = pq.top();
            pq.pop();

            for(auto &it: adj[node]){

                LL newTime = currTime + it.second;

                if(newTime < time[it.first]){

                    ways[it.first] = ways[node];
                    time[it.first] = newTime;
                    pq.push({newTime, it.first});
                }
                else if(newTime == time[it.first])
                ways[it.first] = (ways[it.first] + ways[node]) % MOD;
            }
        }
        return ways[n-1];
    }
};