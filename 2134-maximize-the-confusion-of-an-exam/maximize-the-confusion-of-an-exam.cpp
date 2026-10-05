class Solution {
public:

    int maxConfusion(string key, int k, char toReplace) {
        
        int i = 0, j = 0, operation = 0, ans = 0;

        while (j < key.size()) {

            if (key[j] == toReplace)
                operation++;

            while (operation > k) {

                if (key[i] == toReplace)
                    operation--;

                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(
            maxConfusion(answerKey, k, 'T'),
            maxConfusion(answerKey, k, 'F')
        );
    }
};