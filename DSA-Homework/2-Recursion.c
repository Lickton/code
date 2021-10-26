#include <stdio.h>
#define max(m, n) m > n ? m : n
//* Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int MaxNum(struct ListNode * f) {
    if (f == NULL)
        return 0;
    return max(f->val, MaxNum(f->next));
}

int SumNode(struct ListNode * f) {
    if (f == NULL)
        return 0;
    return SumNode(f->next) + 1;
}

double Aver(struct ListNode * f, int n) {
    n = SumNode(f);
    if (f->next == NULL)
        return f->val;
    double temp = Aver(f->next, n-1);
    return temp + (f->val - temp) / n;
}