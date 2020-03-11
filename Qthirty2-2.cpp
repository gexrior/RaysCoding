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

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> que;
        if(root == NULL) return res;

        //BFS
        que.push(root);
        while(!que.empty()){
            std::vector<int> re;
            int length = que.size(); //每一层的长度
            for(int i = 0; i < length; i++){
                TreeNode* curNode = que.front();
                re.push_back(curNode->val);
                que.pop();
                if(curNode->left) que.push(curNode->left);
                if(curNode->right) que.push(curNode->right);
            }
            res.push_back(re);
        }
        return res;
    }
};