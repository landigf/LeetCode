class Solution {
public:
    int maxProfit(vector<int>& prices) {
        queue<int> queue_prices;
        int res = 0;
        int min_price = 10001;
        for(int price: prices){
            if(price < min_price){
                min_price = price;
            } else if(price > min_price){
                res += (price - min_price);
                min_price = price;
            }
        }
        return res;
    }
};