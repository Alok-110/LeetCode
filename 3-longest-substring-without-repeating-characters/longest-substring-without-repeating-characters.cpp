class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>v (256, -1);
        int i = 0, j = 0, count = 0;

        while(j < s.size()){

            if(v[s[j]] != -1)
            i = max(i, v[s[j]]+1);

            v[s[j]] = j;
            count = max(count, j-i+1);
            j++;
        }
        return count;
    }
};