class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        int maxProfit = 0;
        int minPrice = prices[0];
        for(auto price:prices) {
            minPrice = std::min(minPrice,price);
            int potentialProfit = price - minPrice;
            maxProfit = std::max(potentialProfit, maxProfit);
        }
        return maxProfit;
    }
};
