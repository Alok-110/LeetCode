class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        deque<pair<int, pair<int,int>>> dq;
        vector<vector<int>> obstacle(n, vector<int> (m, 1e9));
        grid[0][0] == 0 ? dq.push_front({0,{0,0}}) : dq.push_front({1,{0,0}});

        while(!dq.empty()){

            auto[currObs, cell] = dq.front();
            auto[ni, nj] = cell;
            dq.pop_front();

            for(int k=0; k<4; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && y>=0 && y<m && x<n){

                    int newObs = grid[x][y] ? currObs+1 : currObs;

                    if(grid[x][y]){
                        if(newObs < obstacle[x][y]){

                            dq.push_back({newObs,{x,y}});
                            obstacle[x][y] = newObs;
                        }
                    }

                    else{
                        if(newObs < obstacle[x][y]){
                            dq.push_front({newObs,{x,y}});
                            obstacle[x][y] = newObs;
                        }
                    }
                    
                }
            }
        }
        return obstacle[n-1][m-1];
         
    }
};