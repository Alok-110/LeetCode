class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> effort(n, vector<int> (m, 1e9));
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        pq.push({0, {0,0}});
        effort[0][0] = 0;

        while(!pq.empty()){

            auto[currEffort, cell] = pq.top();
            auto[ni, nj] = cell;
            pq.pop();

            for(int k = 0; k<4; k++){

                int x = ni+r[k];
                int y = nj+c[k];

                if(x>=0 && x<n && y>=0 && y<m){

                    int nextEffort = max(currEffort, abs(heights[x][y]-heights[ni][nj]));
                    if(nextEffort < effort[x][y]){

                        effort[x][y] = nextEffort;
                        pq.push({nextEffort, {x,y}});
                    }

                }
            }
        }
        return effort[n-1][m-1];

    }
};