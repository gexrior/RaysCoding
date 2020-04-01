//
// Created by xurui on 2020/4/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int num = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<int>> arr(m,vector<int>(n,0));
        if(k == 0)
            return 1;
        dfs(m,n,k,arr,0,0);
        return num;
    }
    void dfs(int m, int n,int k,vector<vector<int>>& arr,int i,int j){
        //1 终止条件
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
        if(i/10 + i%10 + j/10 + j%10 > k)
            return;
        if(arr[i][j] ==1)
            return;
        //2 程序真实逻辑
        num++;
        arr[i][j] =1;
        dfs(m,n,k,arr,i+1,j);
        dfs(m,n,k,arr,i-1,j);
        dfs(m,n,k,arr,i,j+1);
        dfs(m,n,k,arr,i,j-1);
    }
};