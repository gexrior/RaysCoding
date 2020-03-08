//
// Created by xurui on 2020/3/8.
//

#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 };
 */
 struct  ListNode{
     int val;
     ListNode *next;
     ListNode(int x): val(x),next(NULL){}
 };

 /* 解题思路：
  * 1。两次遍历，一个快指针先跑到链表最后，用k来确定慢指针落后步数，输出慢指针
  *
  * */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast){
            if(k>0){
                fast =fast->next;
                k--;
            } else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};

int main(){
    std::cout << "HelloWorld" << std::endl;
    return 0;
}
