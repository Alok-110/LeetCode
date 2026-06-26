class Solution {
public:

    int helper(vector<int> &nums, int k){

        int i = 0, j = 0, count = 0;

        while(j < nums.size()){

            if(nums[j] > k)
            i = j+1;

            count += j-i+1;
            j++;
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return helper(nums, right) - helper(nums, left-1);
    }
};