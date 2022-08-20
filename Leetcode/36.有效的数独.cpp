/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    int row[9], col[9], cell[3][3];
    
    inline int check(int x, int i, int j) {
        int tmp1 = (row[i] >> x) & 1;
        int tmp2 = (col[j] >> x) & 1;
        int tmp3 = (cell[i/3][j/3] >> x) & 1;
        return tmp1 & tmp2 & tmp3;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            row[i] = col[i] = (1 << 9) - 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cell[i][j] = (1 << 9) - 1;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    if (!check(x, i, j))
                        return false;
                    else {
                        row[i] -= 1 << x;
                        col[j] -= 1 << x;
                        cell[i/3][j/3] -= 1 << x;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

