//
// Created by xurui on 2020/3/26.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            if (i >= k -1) ans.push_back(nums[deq.front()]);
        }
        return ans;

    }
};