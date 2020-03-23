//
// Created by xurui on 2020/3/23.
//
#include <vector>
using namespace std;
/* 解题思路
 * dfs:
 * 二分查找，主要逻辑是
 * 当mid在字符串内，nums[mid]+2==nums[mid+1]
 * 之后循环递归调用
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = recursion(nums,0,n-1);
        if(res != -1) return res;
        //特殊情况没有0
        return nums[0] == 0 ? nums[n-1]+1:0;

    }
    int recursion(vector<int>& nums, int left, int right){
        if(left > right ) return -1;
        int mid = left + (right - left)/2;
        if(mid + 1 < nums.size() && nums[mid] + 2 == nums[mid+1]){
            return nums[mid]+1;
        }
        int res1 = recursion(nums,left,mid-1);
        int res2 = recursion(nums,mid+1,right);
        if(res1 == -1)
            return res2;
        return res1;
    }
};
