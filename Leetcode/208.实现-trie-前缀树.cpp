/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    const static int N = 1000010;
    int son[N][26] = {0}, cnt[N], idx = 0;
    
    Trie() {
        
    }
    
    void insert(string word) {
        int p = 0;
        for (int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        for (int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        if (!cnt[p]) return false;
        else return true;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int u = prefix[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

