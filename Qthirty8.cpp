//
// Created by xurui on 2020/3/15.
//
#include <vector>
using  namespace std;
/* 解题思路：
 * 1.使用dfs算法
 * */
class Solution {
public:
    std::vector<string> res;
    std::vector<string> permutation(string s) {
        dfs(s,0);
        return res;
    }
    void dfs(string& s, int pos){
        if(pos >= s.size()){
            res.push_back(s);
            return;
        }
        for(int i = pos; i < s.size(); i++){
            if(judge(s,pos,i)) continue;
            swap(s[pos],s[i]);
            dfs(s,pos+1);
            swap(s[pos],s[i]);
        }
    }
    //如果有重复就跳过
    bool judge(string& s, int start, int end){
        for(int i = start; i < end; i++){
            if(s[i] == s[end]){
                return true;
            }
        }
        return false;
    }
};