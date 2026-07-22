class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        deque<pair<int, pair<int,int>>> dq;
        vector<vector<int>> flips(n, vector<int> (m, 1e9));
        dq.push_front({0, {0,0}});
        flips[0][0] = 0;

        while(!dq.empty()){

            auto[currFlips, cell] = dq.front();
            auto[ni, nj] = cell;
            dq.pop_front();

            for(int k=0; k<4; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && y>=0 && y<m && x<n){

                    int newFlips = 0;
                    if((grid[ni][nj] == 1 && r[k]==0 && c[k]==1) || (grid[ni][nj] == 2 && r[k]==0 && c[k]==-1) 
                    || (grid[ni][nj] == 3 && r[k]==1 && c[k]==0) || (grid[ni][nj] == 4 && r[k]==-1 && c[k]==0)){

                        newFlips = currFlips;
                        if(newFlips < flips[x][y]){

                            dq.push_front({newFlips, {x,y}});
                            flips[x][y] = newFlips;
                        }
                    }
                    else{
                        newFlips = currFlips+1;

                        if(newFlips < flips[x][y]){

                            dq.push_back({newFlips, {x,y}});
                            flips[x][y] = newFlips;
                        }
                    } 
                }
            }
        }
        return flips[n-1][m-1];
    }
};