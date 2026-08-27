class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        using p = pair<int,int>;
        vector<vector<int>> minTime(n, vector<int> (m, 1e9));
        priority_queue<pair<int, p>, vector<pair<int, p>> , greater<pair<int, p>>> pq;

        pq.push({grid[0][0], {0,0}});
        minTime[0][0] = grid[0][0];

        while(!pq.empty()){

            int currMinTime = pq.top().first;
            auto[ni, nj] = pq.top().second;
            pq.pop();

            for(int k=0; k<=3; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && y>=0 && x<n && y<m){

                    int newMinTime = max(currMinTime, grid[x][y]);
                    if(newMinTime < minTime[x][y]){

                        minTime[x][y] = newMinTime;
                        pq.push({newMinTime,{x,y}});
                    }
                }
            } 
        }
        return minTime[n-1][m-1];
    }
};