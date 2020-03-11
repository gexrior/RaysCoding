//
// Created by xurui on 2020/3/11.
//
#include <queue>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*  解题思路：
 *  BFS策略
 * */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        std::vector<int> res;
        std::queue<TreeNode*> que;
        if(root == NULL) return res;

        //BFS逻辑
        que.push(root);
        while(!que.empty()){
            TreeNode* curNode = que.front();
            que.pop();
            res.push_back(curNode->val);
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
        return res;
    }
};