//
// Created by xurui on 2020/3/26.
//

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.length()-1) + s.substr(0,n);
    }
};