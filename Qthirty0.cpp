//
// Created by xurui on 2020/3/10.
//

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s_data; // storage of data
    stack<int> s_min; //storage of min_data
    MinStack() {

    }

    void push(int x) {
        s_data.push(x);
        if(s_min.size() == 0) s_min.push(x);
        else {if(x < s_min.top()) s_min.push(x);
        else{
            s_min.push(s_min.top());
        }}
    }

    void pop() {
        if (s_data.size() == 0) return;
        s_data.pop();
        s_min.pop();
    }

    int top() {
        return s_data.top();
    }

    int min() {
        return s_min.top();
    }
};