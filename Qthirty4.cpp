//
// Created by xurui on 2020/3/12.
//
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* 解题思路：
 * 1.dfs问题
 * 伪代码如下：
 *  判断条件
 *  dfs（每一种选择）
 *  回退到上一步，继续dfs
 * */
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right && !sum) ans.push_back(path);
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back(); //删除向量中的最后一个元素，有效地将容器大小减小了一个。
    }
};