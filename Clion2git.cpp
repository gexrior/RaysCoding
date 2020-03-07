//
// Created by xurui on 2020/3/7.
//
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        bool flag[nums.size()];
        memset(flag,false, sizeof(flag));
        //木桶法，将每一个数字放进木桶，第二次同样的数字会输出
        for(int i = 0; i < nums.size(); i++){
            if(flag[nums[i]]){
                printf("%d ",nums[i]);
                return nums[i];
            }
            else
                flag[nums[i]] = true;
        }
        return -1;
    }
};

int main() {
//    std::cout << "Hello, World!" << std::endl;
    std::vector<int> num = {2,1,1,2,0};
    Solution a;
    a.findRepeatNumber(num);
    return 0;
}
