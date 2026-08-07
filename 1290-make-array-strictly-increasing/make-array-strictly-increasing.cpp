class Solution {
public:

    int find(auto &v2, int prev){
        auto it = upper_bound(v2.begin(), v2.end(), prev);
        if(it == v2.end()) return 1e9; 
        return *it; 
    }

    int memo(auto &v1, auto &v2, int i, int prev, map<pair<int,int>,int> &dp){

        if(i==v1.size()) return 0;
        if(dp.count({i, prev})) return dp[{i, prev}];

        int take = 1e9, skip = 1e9;
        if(prev==-1 || v1[i] > prev)
        take = memo(v1, v2, i+1, v1[i], dp);

        int nextVal = find(v2, prev);
        if(nextVal != 1e9)
        skip = 1 + memo(v1, v2, i+1, nextVal, dp);

        return dp[{i, prev}] = min(take, skip);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        map<pair<int,int>, int> dp;
        int ans = memo(arr1, arr2, 0, -1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};