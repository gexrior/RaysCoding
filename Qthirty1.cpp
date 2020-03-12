//
// Created by xurui on 2020/3/12.
//
#include <stack>
/* 解题思路：
 * 1.如果栈顶元素等于 popped 序列中下一个要 pop 的值，则应立刻将该值 pop 出来
 * */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> st; //栈存放数据
        int n = popped.size();
        int j = 0;
        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};