//
// Created by xurui on 2020/3/8.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct  ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
/* 解题思路：
 * 1.局部转换思想，pre->cur,加一个中间节点t来转换cur->pre
 * cur为代转换节点
 * 2.递归思想
 * fun(){
 * if(终止条件){}
 * fun()//递归函数
 * fun执行逻辑；
 * }
 */
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = NULL;
        while(pre){
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};