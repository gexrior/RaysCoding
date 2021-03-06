//
// Created by xurui on 2020/3/31.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        if(root == p||root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)return root;
        return left ? left : right; // 只有一个非空则返回该指针，两个都为空则返回空指针
    }
};

