class Solution {
public:

    bool canCross(int mid, int row, int col, auto &cells){

        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i = 0; i < mid; i++)
        grid[cells[i][0]-1][cells[i][1]-1] = 1;

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        queue<pair<int,int>> q;
        for(int i=0; i<col; i++)
        if(!grid[0][i]) q.emplace(0,i);

        while(!q.empty()){

            auto[ni, nj] = q.front();
            if(ni==row-1) return true;
            q.pop();

            for(int k=0; k<=3; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && x<row && y>=0 && y<col && !grid[x][y]){

                    q.emplace(x,y);
                    grid[x][y] = 1;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int lo=0, hi=cells.size(), lastDay;

        while(lo<=hi){

            int mid = lo+(hi-lo)/2;

            if(canCross(mid, row, col, cells)){
                lastDay = mid;
                lo = mid+1;
            }
            else
            hi = mid-1;
        }
        return lastDay;
    }
};