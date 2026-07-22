class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, -1, 1};

        queue<pair<int,int>> q;
        int maxArea = 0;

        for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
        if(grid[i][j] == 1){

            q.push({i,j});
            grid[i][j] = 0;
            int area = 0 ;

            while(!q.empty()){

                int ni = q.front().first;
                int nj = q.front().second;
                q.pop();
                area++;

                for(int k = 0; k<=3; k++){

                    if(ni+r[k]>=0 && ni+r[k]<=m-1 && nj+c[k]>=0 && nj+c[k]<=n-1 && grid[ni+r[k]][nj+c[k]] == 1){
                        q.push({ni+r[k],nj+c[k]});
                        grid[ni+r[k]][nj+c[k]] = 0;
                    }
                }
            }
            maxArea = max(maxArea, area); 
        }
        return maxArea;
    }
};