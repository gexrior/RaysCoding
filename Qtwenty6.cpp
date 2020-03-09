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
 * 递归题型，依次判断a中的每一个节点，是否与b中的根结点相等
 * */
class Solution {
public:
    bool momToSon(TreeNode* A, TreeNode* B){
        //B=NUll,终止
        if(A == NULL || B == NULL)
            return B == NULL ? true: false;
        if(A->val != B->val)
            return false;
        //A,B的左右子孩子判断
        return momToSon(A->left,B->left) && momToSon(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //1.终止条件
        if(A == NULL || B == NULL)
            return false;
        //2.递归本身+3.真实逻辑momToSon
        return isSubStructure(A->left, B) || isSubStructure(A->right, B)|| momToSon(A,B);
    }
};