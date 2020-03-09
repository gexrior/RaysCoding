//
// Created by xurui on 2020/3/9.
//

struct  ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
/* 解题思路：***************
 * 双指针问题，画图！
 * 转化数学问题，可以计算出，让快指针先走，再第一次相遇后，
 * 再走“非环部分长度”就是环的起点
 * */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPtr=head, *slowPtr=head;
        // 让fast与slow指针第一次相遇
        while (fastPtr!=NULL && fastPtr->next!=NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if (fastPtr==slowPtr)
            {
                // 从相遇点再走“非环部分长度”一定可以再次走到环起点
                fastPtr = head;
                while (fastPtr != slowPtr)
                {
                    fastPtr = fastPtr->next;
                    slowPtr = slowPtr->next;
                }
                return fastPtr;
                break;
            }
        }

        return nullptr;
    }
};