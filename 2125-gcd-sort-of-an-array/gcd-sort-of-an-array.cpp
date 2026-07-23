class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] > rank[py])
        parent[py] = px;

        else if(rank[py] > rank[px])
        parent[px] = py;

        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    bool gcdSort(vector<int>& nums) {
        
        int n = nums.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i<n; i++) parent[i] = i;
        vector<int> temp = nums;

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            for(int p = 2; p*p <= x; p++){
                if(x % p == 0){
                    if(mp.count(p)) Union(i, mp[p]);
                    else mp[p] = i;
                    while(x % p == 0) x /= p;
                }
            }
            if(x > 1){
                if(mp.count(x)) Union(i, mp[x]);
                else mp[x] = i;
            }
        }

        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++){
            adj[find(i)].push_back(i);
        }

        for(int i = 0; i<n; i++){

            vector<int> index;
            vector<int> number;

            for(auto &it: adj[i]){

                index.push_back(it);
                number.push_back(nums[it]);
            }

            sort(index.begin(), index.end());
            sort(number.begin(), number.end());
            for(int i = 0; i<index.size(); i++){

                temp[index[i]] = number[i];
            }
        }
        sort(nums.begin(), nums.end());
        return temp == nums ? true : false;
    }
};