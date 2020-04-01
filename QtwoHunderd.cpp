//
// Created by xurui on 2020/4/1.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int nums = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++nums;
                    dfs(grid, r, c);
                }
            }
        }

        return nums;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = '0';

        if(i - 1 >=0 && grid[i-1][j] == '1') dfs(grid,i-1,j);
        if(i + 1 <row && grid[i+1][j] == '1') dfs(grid,i+1,j);
        if(j - 1 >=0 && grid[i][j-1] == '1') dfs(grid,i,j-1);
        if(j + 1 <col && grid[i][j+1] == '1') dfs(grid,i,j+1);
    }
};

class Solution {
private:
    vector<int > ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if (!root) return ;

        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
};
var postorderTraversal = function(root) {
    let ans = []
    function dfs(root){
        if (!root) return
                    dfs(root.left)
        dfs(root.right)
        ans.push(root.val)
    }
    dfs(root)
    return ans
};