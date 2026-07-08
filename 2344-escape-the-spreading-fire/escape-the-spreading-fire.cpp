class Solution {
public:

    bool canReach(vector<vector<int>> grid, vector<vector<int>>& fireTime, int mid){

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        q.emplace(0,0);
        grid[0][0] = 2;

        int time = mid+1;

        while(!q.empty()){

            int sz = q.size();
            while(sz--){
                auto[ni, nj] = q.front();
                if(ni == n-1 && nj == m-1) return true;
                q.pop();

                for(int k=0; k<4; k++){

                    int x = ni+r[k];
                    int y = nj+c[k];
                    
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y] != 2){
                        bool valid = (x==n-1 && y==m-1) ? (time <= fireTime[x][y]) : (time < fireTime[x][y]);
                        if(valid){
                            q.emplace(x,y);
                            grid[x][y] = 2;
                        }
                    }
                }
            }
            time++;
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        vector<vector<int>> fireTime(n, vector<int> (m, 1e9));
        queue<pair<int,int>> q;

        for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        if(grid[i][j] == 1){
            q.emplace(i,j);
            fireTime[i][j] = 0;
        }
        int time = 1;
        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                auto[ni, nj] = q.front();
                q.pop();

                for(int k=0; k<4; k++){

                    int x = ni+r[k];
                    int y = nj+c[k];

                    if(x>=0 && x<n && y>=0 && y<m && fireTime[x][y] == 1e9 && grid[x][y] != 2){

                        q.emplace(x,y);
                        fireTime[x][y] = time;
                    }
                }
            }
            time++;
        }
        int lo = 0, hi = n*m, mid, ans=-1;
        while(lo <= hi){

            mid = lo + (hi-lo)/2;

            if(canReach(grid, fireTime, mid)){

                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        if(ans == -1) return ans;
        return fireTime[n-1][m-1] == 1e9 ? 1e9 : ans;        
    }
};