class Solution {
public:

    bool canCross(int n, int m, vector<vector<int>>& cells, int mid){

        vector<vector<int>> v(n, vector<int> (m, 0));
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        for(int i = 0; i<mid; i++)
        v[cells[i][0]-1][cells[i][1]-1] = 1;

        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++){

            if(!v[0][i]){
                q.emplace(0,i);
                v[0][i] = 1;
            }
        }

        while(!q.empty()){

            auto[ni, nj] = q.front();
            if(ni == n-1) return true;
            q.pop();

            for(int k=0; k<4; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && x<n && y>=0 && y<m && !v[x][y]){

                    q.emplace(x,y);
                    v[x][y] = 1;
                }
            }
        }
        return false;        
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int lo = 1, hi = cells.size(), mid, ans=0;

        while(lo <= hi){

            mid = lo + (hi-lo)/2;

            if(canCross(row, col, cells, mid)){
                ans = mid;
                lo = mid+1;
            }
            else
            hi = mid-1;
        }
        return ans;
    }
};