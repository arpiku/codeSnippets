class Solution {
public:
    int _maxProfit(vector<int>& prices, int i, int j) {
        std::cout << "i: " << i << ", j: " << j << std::endl;
        if( i >= j)
            return 0;
        std::cout << "Calcing Price" << std::endl;
        int profit = prices[j] - prices[i];

        int mid = i + (j-1)/2;

  
        profit = std::max(profit, (_maxProfit(prices, i+1, mid) + _maxProfit(prices,mid,j)));
        std::cout << profit << std::endl;
        return profit; 
    }

    int maxProfit2(const std::vector<int>& prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        return maxProfit2(prices);
            
    }


};
