//
// Created by xurui on 2020/3/30.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int price = 999999999;//买入价格
        int profit = 0; //利润
        for(int i = 0;i < prices.size();i++){
            price = min(price,prices[i]);
            profit = max(profit,prices[i] - price);
        }
        return profit;
    }
};