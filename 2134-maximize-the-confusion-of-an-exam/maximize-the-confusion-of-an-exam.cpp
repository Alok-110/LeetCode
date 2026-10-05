class Solution {
public:

    int maxConfusion(string key, int k, char s) {
        
        int i=0, j=0, operation=0, ans=0;

        while(j<key.size()){

            if(key[j]==s)
            operation++;

            while(operation>k){

                if(key[i]==s)
                operation--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        char t = 'T';
        char f = 'F';
        return max(maxConfusion(answerKey, k, t), maxConfusion(answerKey, k, f));
    }
};