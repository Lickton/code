/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < groupSizes.size(); i++) {
            int x = groupSizes[i];
            hash[x].push_back(i);
            if (hash[x].size() == x) {
                res.push_back(hash[x]);
                hash[x].clear();
            }
        }
        return res;
    }
};
// @lc code=end

