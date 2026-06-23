class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int mid, ans;

        while(lo <= hi){

            mid = lo + (hi-lo)/2;

            int sum = 0; int parts = 1;
            for(int i = 0; i<nums.size(); i++){

                sum += nums[i];
                if(sum  > mid){
                    sum = nums[i];
                    parts++;
                }
            }
            if(parts > k) lo = mid+1;
                
            else{
                ans = mid;
                hi = mid-1;
            } 
        }
        return ans;
    }
};