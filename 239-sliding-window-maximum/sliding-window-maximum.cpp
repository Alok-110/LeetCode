class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        for(int i = 0; i<k-1; i++){
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();
            dq.push_back(i);
        }

        int i = 0, j = k-1;
        vector<int> ans;

        while(j<nums.size()){

            while(!dq.empty() && nums[dq.back()] < nums[j])
            dq.pop_back();
            dq.push_back(j);

            ans.push_back(nums[dq.front()]);
            if(dq.front() == i)
            dq.pop_front();
            i++;
            j++;
        }
        return ans;
    }
};