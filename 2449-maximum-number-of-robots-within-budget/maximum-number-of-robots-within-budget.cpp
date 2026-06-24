class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        deque<int> dq;
        long long i = 0, j = 0, robots = 0, cost = 0;

        while(j < chargeTimes.size()){

            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[j])
            dq.pop_back();
            
            dq.push_back(j);
            cost += runningCosts[j];

            while(!dq.empty() && (chargeTimes[dq.front()] + (j-i+1)*cost) > budget){

                if(dq.front() == i) dq.pop_front();
                cost -= runningCosts[i];
                i++;
            }
            robots = max(robots, j-i+1);
            j++;
        }
        return robots;
    }
};