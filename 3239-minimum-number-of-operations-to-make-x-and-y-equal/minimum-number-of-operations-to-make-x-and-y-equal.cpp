class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        
        queue<int> q;
        unordered_set<int> s;
        q.push(x);
        s.insert(x);
        int steps = 0;

        while(!q.empty()){

            int sz = q.size();
            
            while(sz--){

                int num = q.front();
                if(num == y) return steps;
                q.pop();

                if(num % 11 == 0 && !s.contains(num/11)){
                    q.push(num/11);
                    s.insert(num/11);
                } 
                if(num % 5 == 0 && !s.contains(num/5)){
                    q.push(num/5);
                    s.insert(num/5);
                }
                if(!s.contains(num + 1)){
                    q.push(num+1);
                    s.insert(num+1);
                }

                if(!s.contains(num - 1)){
                    q.push(num-1);
                    s.insert(num-1);
                }
            }
            steps++;
        }
        return steps;
    }
};