/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    string path, t;
    unordered_map<char, string> hash {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    int len;
    
    void dfs(int u) {
        if (u == len) {
            res.push_back(path);
            return ;
        }
        
        for (int i = 0; i < hash[t[u]].size(); i++) {
            path.push_back(hash[t[u]][i]);
            // cout << path << endl;
            dfs(u+1);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        len = digits.size();        
        if (len == 0)
            return res;
        
        t = digits;

        dfs(0);
        
        return res;
    }
};
// @lc code=end

