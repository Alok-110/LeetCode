class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int maxi = 0;
        for(auto &it: nums)
        maxi = max(maxi, it);

        return maxi*k + (k)*(k-1)/2;
    }
};