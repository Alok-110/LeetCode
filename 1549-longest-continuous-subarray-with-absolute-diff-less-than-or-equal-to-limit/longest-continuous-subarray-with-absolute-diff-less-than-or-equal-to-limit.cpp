class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> q1;
        deque<int> q2;

        int i = 0, j = 0, count = 0;

        while(j < nums.size()){

            while(!q1.empty() && nums[q1.back()] < nums[j])
            q1.pop_back();
            q1.push_back(j);

            while(!q2.empty() && nums[q2.back()] > nums[j])
            q2.pop_back();
            q2.push_back(j);

            while(nums[q1.front()] - nums[q2.front()] > limit){

                if(q1.front() == i) q1.pop_front();
                if(q2.front() == i) q2.pop_front();
                i++;
            }
            count = max(count, j-i+1);
            j++;
        }
        return count;
    }
};