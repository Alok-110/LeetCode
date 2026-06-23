class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> s;
        int i = 0, j = 0, count = 0;

        while(j < nums.size()){

            s.insert(nums[j]);
            
            while(*s.rbegin() - *s.begin() > limit){

                s.erase(s.find(nums[i]));
                i++;
            }
            count = max(count, j-i+1);
            j++;
        }
        return count;
    }
};