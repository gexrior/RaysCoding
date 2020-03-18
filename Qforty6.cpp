/* 解题思路：
 * 绝大部分树形问题（多叉树或者是二叉树）都可以通过回溯解决，而这道题抽象为树模型后就是：求一颗二叉树从根结点到达叶子结点的路径总数。
 * 因为每次可能的选择都只有两个，犹如二叉树的两个分支。栗如：
 * 对于数字 13 ，你第一次可以只选择一位，那就是 1 ，翻译成字符就是 b；你也可以两位都选，那就是 13 , 翻译成字符为 n。
 * 所以最多就只有两个选择：走左子树或走右子树，走到叶子结点就返回 1 ，代表这条路径可以到达终点。
 * */
class Solution {
public:
    int backtrace(string& str, int pos) {
        int n = str.size();
        if (pos == n) {
            return 1;
        }
        //substr(start_pos,length),从start_pos开始，长度是length的字符串值
        if (pos == n-1 || str[pos] == '0' || str.substr(pos, 2) > "25") {
            return backtrace(str, pos+1);
        }
        return backtrace(str, pos+1) + backtrace(str, pos+2);
    }
    int translateNum(int num) {
        string str = to_string(num);
        return backtrace(str, 0);
    }
};