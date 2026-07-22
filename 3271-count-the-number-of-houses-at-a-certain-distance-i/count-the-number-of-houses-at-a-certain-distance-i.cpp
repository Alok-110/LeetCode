class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> result(n, 0);

        for(int src = 1; src <= n; src++){
            queue<int> q;
            vector<int> vis(n+1, 0);
            q.push(src);
            vis[src] = 1;
            int dist = 0;
            
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    int house = q.front(); 
                    q.pop();

                    if(house != src)
                    result[dist-1]++;
                    
                    if(house+1 <= n && !vis[house+1]){ 
                        q.push(house+1);
                        vis[house+1]=1; 
                    }
                    if(house-1 >= 1 && !vis[house-1]){ 
                        q.push(house-1); 
                        vis[house-1]=1; 
                    }
                    
                    if(house==x && !vis[y]){
                        q.push(y); 
                        vis[y]=1;
                     }
                    if(house==y && !vis[x]){ 
                        q.push(x);
                        vis[x]=1;
                    }
                }
                dist++;
            }
        }
        return result;
    }
};