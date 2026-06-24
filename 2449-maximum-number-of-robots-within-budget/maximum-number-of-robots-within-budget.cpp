class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        multiset<int> s;
        long long i = 0, j = 0, robots = 0, cost = 0;

        while(j < chargeTimes.size()){

            s.insert(chargeTimes[j]);
            cost += runningCosts[j];

            while(!s.empty() && (*s.rbegin() + (j-i+1)*cost) > budget){

                s.erase(s.find(chargeTimes[i]));
                cost -= runningCosts[i];
                i++;
            }
            robots = max(robots, j-i+1);
            j++;
        }
        return robots;
    }
};