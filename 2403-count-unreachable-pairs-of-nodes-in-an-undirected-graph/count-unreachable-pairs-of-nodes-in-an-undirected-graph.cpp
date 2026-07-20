class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(size[px] > size[py]){
            parent[py] = px;
            size[px] += size[py];
        }
        else if(size[px] < size[py]){
            parent[px] = py;
            size[py] += size[px];
        }
        else{
            parent[py] = px;
            size[px] += size[py];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i<n; i++) parent[i]=i;

        for(auto &it: edges)
        Union(it[0], it[1]);

        long long total = (long long)n*(n-1)/2;
        long long reachable = 0;

        unordered_set<long long> st;

        for(int i = 0; i < n; i++){
            int parent = find(i);

            if(!st.count(parent)){
                reachable += (long long)size[parent]*(size[parent]-1)/2;
                st.insert(parent);
            }
        }
        return total - reachable;
    }
};