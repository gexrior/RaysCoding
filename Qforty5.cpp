//
// Created by xurui on 2020/3/18.
//
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 解题思路：
 * 假设对于两个数m和n，如果mn<nm，那么我们认为m小于n，相反如果nm<mn，那么我们认为n<m。
 * */
bool copare(string& s1, string& s2){
    string combine1 = s1+s2;
    string combine2 = s2+s1;
    return combine1 < combine2;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> stradd;
        for(int i = 0; i < nums.size(); i++){
            stradd.push_back(to_string(nums[i]));
        }
        sort(stradd.begin(),stradd.end(),copare);
        string  res = "";
        for(auto str:stradd) res += str;
        return res;
    }
};