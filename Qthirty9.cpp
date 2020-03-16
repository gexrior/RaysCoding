//
// Created by xurui on 2020/3/16.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //1.排序法
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        //2.hash法
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] >= nums.size()/2) return mp[it];
        }
        return 0;
    }
};