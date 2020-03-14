//
// Created by xurui on 2020/3/13.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return dfs(is);
    }

    TreeNode* dfs(istringstream &is) {
        string s;
        is >> s;
        if (s == "#") return nullptr;
        TreeNode *node = new TreeNode(stoi(s));
        node->left = dfs(is);
        node->right = dfs(is);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));