//
// Created by xurui on 2020/3/9.
//


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int n = matrix[0].size(); // column
        int m = matrix.size(); // row
        int col = 0;
        int row = m-1;
        while(row >= 0 && col < n){
            if(matrix[row][col] < target){
                col++;
            } else if(matrix[row][col] >target){
                row--;
            } else{
                return true;
            }
        }
        return false;
    }
};