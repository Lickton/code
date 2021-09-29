/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    // 28/28 cases passed (0 ms)
    // Your runtime beats 100 % of c submissions
    // Your memory usage beats 32.62 % of c submissions (6.4 MB)
    struct ListNode * ptr, * ahead, * tempPtr;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ahead = ptr = head;
    tempPtr = ptr->next;
    ptr->next = NULL;
    while (tempPtr->next != NULL) {
        ptr = tempPtr;
        tempPtr = ptr->next;
        ptr->next = ahead;
        ahead = ptr;
    }
    head = tempPtr;
    head->next = ahead;
    return head;
}
// @lc code=end

