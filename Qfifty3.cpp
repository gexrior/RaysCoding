//
// Created by xurui on 2020/3/20.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        int it=-1;
        while(end>=begin)
        {
            int mid=begin+(end-begin)/2;
            if(nums[mid]>target)end=mid-1;
            else if(nums[mid]==target)
            {
                it=mid;
                break;
            }
            else begin=mid+1;
        }
        if(it==-1)return 0;
        int left=it;
        int right=it;
        while(left>=0&&nums[left]==target)left--;
        while(right<nums.size()&&nums[right]==target)right++;
        return right-left-1;
    }
};