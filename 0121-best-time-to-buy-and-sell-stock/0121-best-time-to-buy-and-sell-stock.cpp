class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int res = 0;
        int min_price = 100000, max_price = -1;
        for(int i = 0; i < n; ++i){
            if(prices[i] < min_price) {
                min_price = prices[i];
                max_price = -1;
            } else if(prices[i] > max_price) {
                max_price = prices[i];
                res = max(res, max_price-min_price);
            }
        }
        return res;
    }
};