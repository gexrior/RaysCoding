//
// Created by xurui on 2020/3/25.
//
#include <vector>

using namespace std;

/* 解题思路：
 * 注意到原题中按从小到大的顺序排列，则可以使用双指针
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum,i=0,j=nums.size()-1;
        vector<int> res;
        while(i < j){
            sum = nums[i] + nums[j];
            if(sum == target){
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }else if(sum > target){
                j--;
            } else i++;
        }
        return res;

    }
};