class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int median, ops = 0;
        if(nums.size() & 1)
        median = nums[(nums.size()-1)/2];
        else
        median = (nums[nums.size()/2] + nums[nums.size()/2-1] )/2;

        for(auto &it: nums)
        ops += abs(median-it);

        return ops;
    }
}; 