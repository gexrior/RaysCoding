//
// Created by xurui on 2020/3/25.
//

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >=0; m--)
        {
            if(s[m]==' '&&len!=0)
            {
                ans += s.substr(m+1,len)+ " ";len = 0; continue;
            }
            if(s[m]!= ' ')len++;
        }
        if(len !=0) ans += s.substr(0,len) + " ";
        if(ans.size()>0)ans.erase(ans.size()-1,1);
        return ans;

    }
};