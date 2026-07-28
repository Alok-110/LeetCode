class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int posSum = 0, negSum = 0, posMax = 0, negMax = 0;
        for(int i=0; i<nums.size(); i++){

            posSum += nums[i];
            negSum += nums[i];

            posMax = max(posMax, posSum);
            negMax = min(negMax, negSum);
            if(posSum<0) posSum = 0; 
            if(negSum>0) negSum = 0; 
        }
        return max(posMax, abs(negMax));
    }
};