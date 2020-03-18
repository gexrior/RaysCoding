//
// Created by xurui on 2020/3/18.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
        int maxValue(vector<vector<int>>& grid) {
            int r = grid.size(), c = grid[0].size();
            vector<int> dp(c+1,0);
            for(int i = 0; i < dp.size(); i++)
                std::cout << dp[i] << endl;
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    dp[j+1] = max(dp[j],dp[j+1]) + grid[i][j];
                }
            }
            return dp[c];
        }
};