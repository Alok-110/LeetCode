class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         
        int n = nums.size();
        int lastSeenOdd = n;
        vector<int> nextOdd(n);
        for(int i=n-1; i>=0; i--){

            nextOdd[i] = lastSeenOdd;
            if(nums[i]&1)
            lastSeenOdd = i;

        }

        int i=0, j=0, count=0, odds=0;

        while(j<nums.size()){

            if(nums[j] & 1)
            odds++;

            while(odds==k){

                count += nextOdd[j]-j;
                
                if(nums[i]&1)
                odds--;
                i++;
            }
            j++;

        }
        return count;
    }
};