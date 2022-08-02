/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    const static int N = 200020, M = 31 * N;
    int son[M][2], idx;
    
    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }
    
    int query(int x) {
        int p = 0, res = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (son[p][!u]) {
                res += (1 << i);
                p = son[p][!u];
            } else p = son[p][u];
        }
        
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
            res = max(res, query(nums[i]));
        }
        
        return res;
    }
};
// @lc code=end

