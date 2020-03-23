//
// Created by xurui on 2020/3/23.
//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return (!root)?0:max(maxDepth(root->left), maxDepth(root->right))+1;

    }
};