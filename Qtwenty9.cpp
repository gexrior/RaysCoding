//
// Created by xurui on 2020/3/10.
//
#include "vector"

/* 解题思路：
 * 1.方向题型，用left,right,top,bottom四个变量标示
 * 2.使用【0，1】【1，0】【0，-1】【-1，0】表示右，下，上，左方向
 * */
class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> res;
        while(1){
            if(left > right) break;
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            if(top > bottom) break;
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left > right) break;
            for(int i = right; i >= left; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(bottom < top) break;
            for(int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int size = matrix.size() * matrix[0].size(); // 矩阵中元素总数

        int row = 0; // 当前行号
        int col = 0; // 当前列号
        int d = 0; // 当前方向

        int rowUpLimit = 0; // 行最大限制
        int colUpLimit = 0; // 列最大限制
        int rowDownLimit = matrix.size() - 1; // 行最小限制
        int colDownLimit = matrix[0].size() - 1; // 列最小限制

        bool change = false; // 是否改变过方向
        int changeTime = 0; // 改变方向的次数

        res.push_back(matrix[row][col]);
        for (int i = 0; i < size; i++) {
            row = row + dir[d].first;
            col = col + dir[d].second;
            while (row < rowUpLimit || row > rowDownLimit || col < colUpLimit || col > colDownLimit) {
                row = row - dir[d].first;
                col = col - dir[d].second;
                d = (d + 1) % 4;
                row = row + dir[d].first;
                col = col + dir[d].second;

                change = true;
                changeTime++;
                if (changeTime > 1) { // 方向更替一定是右->下->左->上->右的循环，每次只可能改变一个方向，因此当改变一次方向不够的时候，所有的数字都已经遍历过
                    return res;
                }
            }
            changeTime = 0;
            if (change == true) {
                if (d == 1) {
                    rowUpLimit++;
                } else if (d == 2) {
                    colDownLimit--;
                } else if (d == 3) {
                    rowDownLimit--;
                } else {
                    colUpLimit++;
                }

                change = false;
            }

            res.push_back(matrix[row][col]);
        }
        return res;
    }
};