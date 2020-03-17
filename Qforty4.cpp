//
// Created by xurui on 2020/3/17.
//
/* pow函数的作用是求幂。
 * 数学公式：计算x的y次幂；
 * 返回值：x不能为负数且y为小数，或者x为0且y小于等于0，返回幂指数的结果；
 * 返回类型：double型。
 * */
class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        int base=1;
        while(n>9*pow(10,base-1)*base){
            n-=9*pow(10,base-1)*base;
            base++;
        }//计算n在哪个位数区间
        int res=pow(10,base-1)+n/base;
        int mod=n%base;
        if(mod==0) return (res-1)%10;
        else return res/(int)pow(10,base-mod)%10;
    }
};