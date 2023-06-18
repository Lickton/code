/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        stack<ListNode*> stk;
        ListNode *prev, *next;
        if (left == 1) prev = nullptr;
        
        for (auto i = head; i; i = i->next) {
            cnt ++;
            if (cnt == left - 1) prev = i;
            if (cnt >= left && cnt <= right) stk.push(i);
            if (cnt == right + 1) next = i;
        }
        if (cnt == right) next = nullptr;
        
        stk.push(prev);
        while (stk.size() > 1) {
            if (stk.top() == nullptr) {
                stk.pop();
                head = stk.top();
            } else {
                auto p = stk.top(); stk.pop();
                p->next = stk.top();
            }
        }
    
        stk.top()->next = next;
        return head;
    }
};
// @lc code=end

