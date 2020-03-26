//
// Created by xurui on 2020/3/26.
//

class MaxQueue {
public:
    queue<int> q;
    deque<int> maxq;
    MaxQueue() {

    }

    int max_value() {
        if(q.empty() || maxq.empty())
        {
            return -1;
        }
        else
        {
            return maxq.front();
        }
    }


    void push_back(int value) {
        q.push(value);
        while(!maxq.empty() && value > maxq.back())
        {
            maxq.pop_back(); //不用保留比value小的数字的原因是
            //比value进来早的数字也比value更先弹出，所以不用担心最大值是被扔掉的数字
        }
        maxq.push_back(value);
    }

    int pop_front() {
        if(!q.empty())
        {
            int num = q.front();
            q.pop();
            if(num ==  maxq.front())
            {
                maxq.pop_front();
            }
            return num;
        }
        return -1;
    }
};