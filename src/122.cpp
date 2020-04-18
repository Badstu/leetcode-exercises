#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        
        int profit = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};