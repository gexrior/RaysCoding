//
// Created by xurui on 2020/3/24.
//

class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left), right = dfs(root->right);
        if(abs(left-right) > 1) ans = false;
        return max(left,right) +1;

    }
};