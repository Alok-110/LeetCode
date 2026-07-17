class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for(int i = 0; i<n; i++){

            if(color[i] != -1) continue;

            q.push(i);
            color[i] = 0;

            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(auto &it: graph[node]){

                    if(color[it] == color[node])
                    return false;

                    if(color[it] == -1){

                        color[it] = !color[node];
                        q.push(it);
                    }
                }
            }
        }
        return true;
    }
};