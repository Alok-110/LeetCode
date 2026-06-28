class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int i = 0, j = 0, count = 0;
        long long windowSum = 0;
        sort(nums.begin(), nums.end());

        while(j < nums.size()){

            windowSum += nums[j];

            while(((long long)nums[j] * (j-i+1) - windowSum) > k){

                windowSum -= nums[i];
                i++;
            }
            count = max(count, j-i+1);
            j++;
        }
        return count;
    }
};