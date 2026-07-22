class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        int count = 0;

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(board[i][j] == 'X'){

                    q.push({i,j});
                    board[i][j] = '.';
                    count++;

                    while(!q.empty()){

                        int ni = q.front().first;
                        int nj = q.front().second;
                        q.pop();

                        for(int k = 0; k<=3; k++){

                            int x = ni+r[k];
                            int y = nj+c[k];

                            if(x>=0 && x<n && y>=0 && y<m && board[x][y] == 'X'){

                                q.push({x,y});
                                board[x][y] = '.';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};