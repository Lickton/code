/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    static const int N = 9;
    unordered_map<int, int> ones, hash;
    int row[N], col[N], cell[3][3];
    
    inline int lowbit(int x) {
        return x & -x;
    }
    
    inline int get(int x, int y) {
        return row[x] & col[y] & cell[x/3][y/3];
    }
    
    bool dfs(vector<vector<char>> &board, int cnt) {
        if (!cnt) return true;
        int minv = 10, x, y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') {
                    int t = ones[get(i, j)];
                    if (t < minv) {
                        minv = t;
                        x = i, y = j;
                    }
                }
            }
        }
        
        for (int i = get(x, y); i; i -= lowbit(i)) {
            int t = hash[lowbit(i)];
            row[x] -= 1 << t;
            col[y] -= 1 << t;
            cell[x/3][y/3] -= 1 << t;
            
            board[x][y] = '1' + t;
            if (dfs(board, cnt-1))
                return true;
            
            row[x] += 1 << t;
            col[y] += 1 << t;
            cell[x/3][y/3] += 1 << t;
            board[x][y] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; i++)
            row[i] = col[i] = (1 << N) - 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cell[i][j] = (1 << N) - 1;
        }
        for (int i = 0; i < N; i++)
            hash[1<<i] = i;
        for (int i = 0; i < 1 << N; i ++) {
            int s = 0;
            for (int j = i; j; j -= lowbit(j)) s++;
            ones[i] = s;
        }
        
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i] -= 1 << t;
                    col[j] -= 1 << t;
                    cell[i/3][j/3] -= 1 << t;
                } else cnt++;
            }
        }
        dfs(board, cnt);
    }
};
// @lc code=end

