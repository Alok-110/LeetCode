class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int i = 0, j = k-1, count = 0, sum = 0;
        for(int p = 0; p<j; p++) sum+=arr[p];

        while(j < arr.size()){

            sum += arr[j];

            if(sum/(j-i+1) >= threshold) count++;
            sum -= arr[i];
            i++;
            j++;
        }
        return count;
    }
};