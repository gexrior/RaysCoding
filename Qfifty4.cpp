//
// Created by xurui on 2020/3/23.
//
//解题思路：后序遍历-》右根左
class Solution {
public:
    int ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* root, int &k){
        if (!root) return;
        dfs(root->right, k);
        k --;
        if(!k) ans = root->val;
        if(k > 0) dfs(root->left, k);
    }
};
//解题思路：中序遍历左根右
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> result;
        dfs(result, root);
        return result[k-1];
    }

private:
    void dfs(vector<int> &result, TreeNode *node) {
        if (node == nullptr) return;
        dfs(result, node->right);
        result.push_back(node->val);
        dfs(result, node->left);
    }
};