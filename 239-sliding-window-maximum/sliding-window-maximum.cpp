class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        for(int i = 0; i<k-1; i++){
            while(!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();
            q.push_back(i);
        }

        int i = 0, j = k-1;
        vector<int> ans;
        while(j < nums.size()){

            while(!q.empty() && nums[q.back()] < nums[j])
            q.pop_back();
            q.push_back(j);

            ans.push_back(nums[q.front()]);
            if(q.front() == i)
            q.pop_front();
            i++;
            j++;
        }
        return ans;
    }
};