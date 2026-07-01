class Solution {
public:

    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int i = 0, j = 0, sum = 0, maxSum = 0;

        while(j < nums.size()){

            sum += nums[j];
            mp[nums[j]]++;

            while(mp[nums[j]] > 1){

                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            maxSum = max(maxSum, sum);
            j++;
        }
        return maxSum;
    }
};