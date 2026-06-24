class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        int i = 0, j = k;
        vector<int> ans;

        for(int p = 0; p<k; p++){

            while(!dq.empty() && nums[dq.back()] <= nums[p])
            dq.pop_back();
            dq.push_back(p);
        }
        ans.push_back(nums[dq.front()]);

        while(j < nums.size()){

            while(!dq.empty() && nums[dq.back()] <= nums[j])
            dq.pop_back();

            dq.push_back(j);
            if(dq.front() == i) dq.pop_front();
            ans.push_back(nums[dq.front()]);            
            i++;
            j++;
        }
        return ans;
    }
};