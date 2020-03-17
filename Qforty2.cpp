//
// Created by xurui on 2020/3/17.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxSum = nums[0];

        // 如果当前值小于0，
        // 重新开始(全局最大值更新)
        for (int i = 1; i < n; i++) {
            // 更新当前的最大值
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            // 更新全局的最大值
            maxSum = std::max(nums[i], maxSum);
        }

        return maxSum;
    }
};