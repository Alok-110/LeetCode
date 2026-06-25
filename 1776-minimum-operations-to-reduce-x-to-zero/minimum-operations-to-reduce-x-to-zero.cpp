class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int i = 0, j = 0, sum = 0, count = -1;
        for(auto &it: nums) sum+=it;

        int requiredSum = sum - x;
        if(requiredSum < 0 ) return -1;
        sum = 0;

        while(j < nums.size()){

            sum += nums[j];

            while(sum > requiredSum){

                sum -= nums[i];
                i++;
            }
            if(sum == requiredSum) count = max(count, j-i+1);
            j++;
        }
        return count == -1 ? -1 : nums.size() - count;
    }
};