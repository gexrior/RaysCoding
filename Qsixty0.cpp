//
// Created by xurui on 2020/3/27.
//
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[15][70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = i; j <= 6*i; j ++) {
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur <= 0) {
                        break;
                    }
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[n][i] * 1.0 / all);
        }
        return ret;
    }
};

int main (){
    Solution* obj = new Solution();

    vector<double> res;
    res = obj->twoSum(5);

    for(int i=0; i < res.size();i++)
        std::cout << res[i];

    return 0;
}