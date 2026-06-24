class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int windowSize = n-k;

        int totalSum = 0;
        for(auto &it: cardPoints) totalSum += it;
        if(k == n) return totalSum;

        int i = 0, j = n-k-1, count = 0, sum = 0, minSum = 1e9;
        for(int p = 0; p<j; p++) sum += cardPoints[p];

        while(j < cardPoints.size()){

            sum += cardPoints[j];
            minSum = min(minSum, sum);

            sum -= cardPoints[i];
            i++;
            j++;
        }
        return totalSum - minSum;
    }
};