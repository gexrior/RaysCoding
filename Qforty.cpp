//
// Created by xurui on 2020/3/16.
//
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
//     1.排序后找到对应值
//    vector<int> getLeastNumbers(vector<int>& arr, int k) {
//        sort(arr.begin(),arr.end());
//        vector<int> res;
//        for(int i = 0; i < k; i++){
//            res.push_back(arr[i]);
//        }
//        return res;
//    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len = arr.size()-1;
        Qsort(arr, 0, len);
        vector<int> ans;
        for(int i = 0;i < k;i++)
            ans.push_back(arr[i]);
        return ans;
    }
    /* 快排逻辑
     * 1.设置第一个值为基准值key
     * 2.传入low(左➡️右)，high（右⬅️左）两个卫兵
     * 3.通过while循环，找到arr[++i]>key,arr[--j]<key,交换
     * 4.跳出循环，改变基准值，继续迭代
     * */
    void Qsort(vector<int>& arr, int low, int high){
        if (high <= low)
            return;

        int i = low;
        int j = high + 1;
        int key = arr[low];
        while(true){
            /*从左向右找比key大的值*/
            while (arr[++i] < key)
            {
                if (i == high)
                    break;
            }
            /*从右向左找比key小的值*/
            while (arr[--j] > key)
            {
                if (j == low)
                    break;
            }
            if (i >= j)
                break;
            /*交换i,j对应的值*/
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        Qsort(arr,low,j-1);
        Qsort(arr,j+1,high);
    }
};