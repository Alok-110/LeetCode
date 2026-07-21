class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        bool found = false;
        for (int i = 0; i < n && !found; i++)
        for (int j = 0; j < n && !found; j++)
        if (grid[i][j] == 1){
                q1.emplace(i, j);
                q2.emplace(i,j);
                grid[i][j] = 2;
                found = true;
            }
        
        while(!q1.empty()){
            auto[ni, nj] = q1.front();
            q1.pop();

            for(int k = 0; k<4; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 1){

                    q1.emplace(x,y);
                    q2.emplace(x,y);
                    grid[x][y] = 2;
                }
            }
        }
        int zeros = 0;
        while(!q2.empty()){

            int sz = q2.size();
            while(sz--){

                auto[ni, nj] = q2.front();
                q2.pop();

                for(int k = 0; k<4; k++){

                    int x = ni+r[k];
                    int y = nj+c[k];

                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y] != 2){

                        if(grid[x][y] == 1) return zeros;
                        q2.emplace(x,y);
                        grid[x][y] = 2;
                    }
                }
            }
            zeros++;
        }
        return zeros;
    }
};