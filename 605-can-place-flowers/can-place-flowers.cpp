class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int emptyPlots = 1; // virtual 1 before start
        int flowers = 0;

        for(int i = 0; i < flowerbed.size(); i++){
            if(!flowerbed[i])
                emptyPlots++;
            else{
                flowers += (emptyPlots-1)/2;
                emptyPlots = 0;
            }
        }
        emptyPlots++;
        flowers += (emptyPlots-1)/2;
        
        return flowers >= n;
    }
};