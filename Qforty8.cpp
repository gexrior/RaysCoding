//
// Created by xurui on 2020/3/19.
//
#include <string>
#include <map>
using namespace std;
/* 解题思路：
 * 本题中我们需要得到的是不重复字符的子字符串，
 * 而子字符串在这里是要求连续的，那么可以类似于一个窗口卡主了这个不重复子串的左边与右边
 * 初始化窗口的左右边界都为0，我们以右边界遍历，以map来判断当前元素是否在之前已经被使用
 * 也就是去重，若碰到重复元素，那么在[l,r]区间内，必定有重复元素呗，恢复现场同时让l右移
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //设置窗口
        map<char,int> ump;
        //设置左右指针
        int res;
        int l = 0,r = 0;
        while(l <= r && r < s.size()){
            //当前元素不再窗口内，则r++
            if(ump[s[r]] == 0){
                ump[s[r]]++;
                r++;
                res = max(res,r-l);
            }
            else if(ump[s[r]] > 0 ){ //当前集合中存在这个元素，则左指针++
                //清除ump中的元素
                ump[s[l]]--;
                l++;
            }
        }
        return res;

    }
};