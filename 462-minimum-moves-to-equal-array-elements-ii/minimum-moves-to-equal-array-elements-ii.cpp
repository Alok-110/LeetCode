class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int median, ops = 0;
        median = nums[(nums.size()-1)/2];

        for(auto &it: nums)
        ops += abs(median-it);

        return ops;
    }
}; 