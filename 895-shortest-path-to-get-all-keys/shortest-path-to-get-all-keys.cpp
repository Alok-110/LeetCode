class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        using V = vector<int>;
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        queue<tuple<int,int,int>> q;
        vector<vector<V>> vis(n, vector<V> (m, V (1<<6, 0)));
        int keys = 0;     

        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){

            if(grid[i][j] == '@'){
                q.emplace(i,j,0);
                vis[i][j][0] = 1;
            }
            else if(islower(grid[i][j]))
            keys++;
        }
        
        int dist = 0;
        while(!q.empty()){

           int sz = q.size();
           while(sz--){

                auto[ni, nj, mask] = q.front();
                q.pop();
                if(mask == (1<<keys) - 1)
                return dist;

                for(int k=0; k<4; k++){

                    int x = ni+r[k];
                    int y = nj+c[k];

                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y] != '#'){

                        if(isupper(grid[x][y]) && !(mask & 1<<(grid[x][y]-'A')))
                        continue;

                        if(islower(grid[x][y])){

                            int newMask = mask | 1<<(grid[x][y]-'a');
                            if(vis[x][y][newMask]) continue;
                            q.emplace(x,y,newMask);
                            vis[x][y][newMask] = 1;
                        }
                        else{
                            if(vis[x][y][mask]) continue;
                            q.emplace(x,y,mask);
                            vis[x][y][mask] = 1;
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};