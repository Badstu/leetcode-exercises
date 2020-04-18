class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        int min_cur = INT_MAX;
        int profit = 0;

        for(int i = 0; i < n; i++){
            if(prices[i] < min_cur){
                min_cur = prices[i];
            } else{
                profit = max(profit, prices[i] - min_cur);
            }
        }

        return profit;
    }
};