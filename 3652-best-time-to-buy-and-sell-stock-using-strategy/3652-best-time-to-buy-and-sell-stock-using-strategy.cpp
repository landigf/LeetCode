class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> original(n+1), full(n+1);
        for(int i = 1; i <= n; ++i){
            original[i] = prices[i-1]*strategy[i-1];
            original[i] += original[i-1];
            full[i] = prices[i-1] + full[i-1];
        }
        int l = 1, r = k;
        long long res = original[n];
        while(r <= n){
            int i = l + (r-l)/2;
            long long curr = 0;
            curr += original[l-1] - original[0];
            curr += original[n] - original[r];
            curr += full[r] - full[i];
            res = max(res, curr);
            ++l; ++r;
        }
        return res;
    }
};