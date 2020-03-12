//
// Created by xurui on 2020/3/12.
//
#include <vector>
/* 解题思路：
 * 1.左子树< root <右子树
 * */
class Solution {
public:
    bool verifyPostorder(std::vector<int>& postorder) {
        if(postorder.size() < 2) return true;
        return rsvLeftRight(postorder, 0, postorder.size()-1);
    }
    bool rsvLeftRight(std::vector<int>& postorder,int start, int end){
        if(start >= end) return true;
        int bound;
        int i = start;
        while(postorder[i] < postorder[end]){
            i++; //i为左子树，i++就是右子树
        }
        bound = i; //判断右子树和root的关系
        for(; i<end; i++)   //右子树应该小于根节点，否则不是二叉搜索树
        {
            if(postorder[i] < postorder[end]) return false;//循环是为了防止子树为null
        }

        return rsvLeftRight(postorder,start,bound-1) && rsvLeftRight(postorder,bound,end);
    }
};