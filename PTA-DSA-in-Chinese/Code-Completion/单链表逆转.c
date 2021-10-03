typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Reverse(List L) {
    if (L == NULL || L->Next == NULL) {
        return L;
    }
    struct Node * cur, * pre;
    pre = L;
    cur = L->Next; 
    pre->Next = NULL;
    while (cur != NULL) {
        struct Node * temp = cur->Next;
        cur->Next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}