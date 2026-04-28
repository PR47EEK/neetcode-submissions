class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprft = 0;
        int minprice = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(i == 0) {
                minprice = prices[i];
                continue;
            }
            maxprft = max(maxprft, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprft;
    }
};
