/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution {
public:
    // 987/987 cases passed (4 ms)
    // Your runtime beats 97.26 % of cpp submissions
    // Your memory usage beats 83.74 % of cpp submissions (6.8 MB)
    int max(int m, int n) {
        return m > n ? m : n;
    }

    int lengthOfLongestSubstring(string s) {
        int h[127] = {0}, res = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            h[s[i]]++;
            while (h[s[i]] > 1) {
                h[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
// @lc code=end

