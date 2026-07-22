class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        queue<pair<int,int>> q;
        q.emplace(0,0);
        grid[0][0] = 1;

        int path = 1;
        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                auto[ni,nj] = q.front();
                q.pop();
                if(ni==n-1 && nj==n-1) return path;
                
                for(int r=-1; r<2; r++)
                for(int c=-1; c<2; c++){

                    int x = ni + r;
                    int y = nj + c;

                    if(x>=0 && y>=0 && y<n && x<n && !grid[x][y]){

                        q.emplace(x,y);
                        grid[x][y] = 1;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};