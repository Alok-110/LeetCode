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

        if(rank[px] < rank[py])
        parent[px] = py;

        else{
            parent[py] = px;
            rank[px]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i<26; i++) parent[i] = i;

        for(auto &it: equations){

            if(it[1] == '=')
            Union(it[0]-'a', it[3]-'a');
        }

        for(auto &it: equations){

            int p1 = find(it[0]-'a');
            int p2 = find(it[3]-'a');

            if(it[1] == '!' && p1==p2)
            return false;
        }
        return true;
    }
};