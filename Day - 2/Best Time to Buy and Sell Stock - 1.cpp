class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        int N = prices.size();
        
        for(int i = 0; i<N; i++){
            if(prices[i] < min_price) min_price = prices[i];
            else {
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};
