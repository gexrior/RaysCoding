//
// Created by xurui on 2020/3/8.
//

struct  ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
/* 解题思路：
 * 1.各链表各拿一个出来比较，直到某一链表为空，将非空链表接到最后
 * */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(-1);
        ListNode* ret = p;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            } else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 == NULL ? l2 : l1;
        return ret->next;
    }
};