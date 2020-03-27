//
// Created by xurui on 2020/3/27.
//

class Solution {
public:
    int lastRemaining(int n, int m) {
        int res=0;
        for(int i=2;i<=n;i++)
            res=(res+m)%i;
        return res;
    }
};