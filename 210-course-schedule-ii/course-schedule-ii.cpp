class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses;
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        queue<int> q;

        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){

                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){

                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans.size()==n ? ans : vector<int>{};
    }
};