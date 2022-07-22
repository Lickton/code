/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    stack<int> num;
    stack<char> op;

    string replace(string s) {
        string res;
        for (auto c : s) {
            if (c == '+') {
                if (res.empty() || res.back() == '(') res += "0+";
                else res.push_back(c);
            } else if (c == '-') {
                if (res.empty() || res.back() == '(') res += "0-";
                else res.push_back(c);
            } else if (c != ' ') res.push_back(c);
        }
        return res;
    }

    void eval() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int x;

        if (c == '+') x = a + b;
        else if (c == '-') x = a - b;

        num.push(x);
    }

    int calculate(string s) {
        unordered_map<char, int> pr{{'+', 1}, {'-', 1}};
        s = replace(s);
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                i = j - 1;
                num.push(x);
            } else if (c == '(') 
                op.push(c);
            else if (c == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                while (op.size() && pr[op.top()] >= pr[c]) eval();
                op.push(c);
            }
        }

        while (op.size()) eval();

        return num.top();
    }
};
// @lc code=end

