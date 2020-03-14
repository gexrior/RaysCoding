//
// Created by xurui on 2020/3/13.
//
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/* 解题思路：
 * 1.使用UnorderMap存键值对
 * */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return  NULL;
        //将节点传进umap中
        Node* pNode = head;
        std::unordered_map<Node*,Node*> ummap;
        while(pNode != NULL){
            ummap[pNode] = new Node(pNode->val);
            pNode = pNode->next;
        }
        //设置next和random指针
        pNode = head;
        while(pNode !=NULL) {
            ummap[pNode]->next = ummap[pNode->next];
            ummap[pNode]->random = ummap[pNode->random];
            pNode = pNode->next;
        }
        return ummap[head];
    }
};