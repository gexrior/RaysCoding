//
// Created by xurui on 2020/3/10.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 解题思路：
 * 递归调用
 * 使用isEqual()判断是否相等
 * */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode* A, TreeNode* B){
        if(A == NULL && B == NULL){
            return true;
        }
        if(A == NULL || B == NULL){
            return false;
        }
        if(A->val != B->val){
            return false;
        }
        return isEqual(A->left,B->right) && isEqual(A->right,B->left);

    }
};