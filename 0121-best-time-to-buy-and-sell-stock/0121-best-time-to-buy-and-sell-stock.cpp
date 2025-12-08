class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int last_min = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] < prices[last_min]) last_min = i;
            else res = max(res, prices[i] - prices[last_min]);
        }
        return res;
    }
};