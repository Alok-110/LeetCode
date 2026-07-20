class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        unordered_map<int,int> mp;
        int id = 2;
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){

            if(grid[i][j] == 1){

                q.emplace(i,j);
                grid[i][j] = id;
                int area = 1;

                while(!q.empty()){

                    auto[ni, nj] = q.front();
                    q.pop();

                    for(int k=0; k<4; k++){

                        int x = ni+r[k];
                        int y = nj+c[k];

                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 1){

                            q.emplace(x,y);
                            grid[x][y] = id;
                            area++;
                        }
                    }
                }
                mp[id] = area;
                id++;
            }
        }
        int maxArea = 0;
        for(auto &it: mp) maxArea = max(maxArea, it.second);
        for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){

            int area = 0;
            unordered_set<int> st;
            if(grid[i][j] == 0){

                for(int k=0; k<4; k++){
                    int x = i+r[k];
                    int y = j+c[k];

                    if(x>=0 && x<n && y>=0 && y<n)
                    st.insert(grid[x][y]);
                }
                for(auto &it: st)
                area += mp[it];                
            }
            maxArea = max(area+1, maxArea);
        }
        return maxArea;
    }
};