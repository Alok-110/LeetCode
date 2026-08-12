class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double costs = 0;
        int x = min(prices.size(), discounts.size());
        
        for(int i=0; i<x; i++){

            costs += prices[i]*(100.0-discounts[i])/100.0;
        }

        if(prices.size() > discounts.size()){

            for(int i=discounts.size(); i<prices.size(); i++)
            costs+=prices[i];
        }
        return costs;
    }
};
