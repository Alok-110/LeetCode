class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> bestHealth(n, vector<int> (m, -1));

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        q.push({{0,0}, health - grid[0][0]});
        bestHealth[0][0] = health-grid[0][0];

        while(!q.empty()){

            auto[ni, nj] = q.front().first;
            int currHealth = q.front().second;

            if(ni == n-1 && nj == m-1 && currHealth >= 1) return true;
            q.pop();

            for(int k = 0; k<=3; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && x<n && y>=0 && y<m){

                    int newHealth = currHealth - grid[x][y];

                    if(newHealth > bestHealth[x][y]){
                        q.push({{x,y}, newHealth});
                        bestHealth[x][y] = newHealth;
                    }
                }
            }
        }
        return false;
    }
};