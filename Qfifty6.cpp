//
// Created by xurui on 2020/3/24.
//

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2,0);
        int number = 0;
        for(int num:nums)
            number ^= num;
        int pos =  number&(-number);
        for(int num:nums)
        {
            if((num & pos)==pos) //这个位置是1的数字，放到第一个数组里做异或运算
            {
                res[0] ^=num;
            }
            else
            {
                res[1] ^=num;
            }
        }
        return res;
    }
};