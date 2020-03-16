//
// Created by xurui on 2020/3/16.
//

class MedianFinder {
    priority_queue<int> lo;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // 加到大顶堆

        hi.push(lo.top());                               // 平衡
        lo.pop();

        if (lo.size() < hi.size()) {                     // 维护两个堆元素个数
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};