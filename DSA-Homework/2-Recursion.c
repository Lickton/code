#include <stdio.h>
#include <stdlib.h>
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
    return SumNode(f->next) + f->val;
}

double Aver(struct ListNode * f, int n) {
    if (f->next == NULL)
        return f->val;
    double temp = Aver(f->next, n-1);
    return temp + (f->val - temp) / n;
}

int main() {
    struct ListNode * f = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * head = f;
    char c;
    int num, count = 0;
    while (1) {
        scanf("%d%c", &num, &c);
        f->val = num;
        count++;
        f->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        f = f->next;
        if(c == '\n')
            break;
    }
    printf("Max:%d\tSum:%d\tAver:%lf\n", MaxNum(head), SumNode(head), Aver(head, count));
    return 0;
}