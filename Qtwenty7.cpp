//
// Created by xurui on 2020/3/9.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* 解题思路：
 * 中间值+递归
 * */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root){
            TreeNode* temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }
};