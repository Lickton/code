/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

#include <stdio.h>
//* Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //  Recursion O(m+n)
    //  208/208 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 88.84 % of c submissions (5.9 MB)
    if (l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    if (l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    
    //  Iteration O(m+n)
    //  208/208 cases passed (0 ms)
    //  Your runtime beats 100 % of c submissions
    //  Your memory usage beats 88.84 % of c submissions (5.9 MB)
    /*
    struct ListNode * current, * head;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    head = current = l1->val < l2->val ? l1 : l2;
    if (current == l1)
            l1 = l1->next;
        else
            l2 = l2->next;
    while (l1 != NULL && l2 != NULL){
        current->next = l1->val < l2->val ? l1 : l2;
        current = current->next;
        if (current == l1)
            l1 = l1->next;
        else
            l2 = l2->next;
    }
    if (l1 == NULL)
        current->next = l2;
    else
        current->next = l1;
    return head;
    */

    
    //  Iteration O(m+n)
    /*
    struct ListNode * current, * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    current->next = l1 == NULL ? l2 : l1;
    return head->next;
    */
}
// @lc code=end

