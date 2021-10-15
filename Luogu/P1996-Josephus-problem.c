#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node * next;
}List;

List * InitList(int numSize) {
    int i;
    List * head, * current;
    head = malloc(sizeof(List));
    head->val = 1;
    head->next = NULL;
    current = head;
    for (i = 2; i <= numSize; i++) {
        List * tempCell = malloc(sizeof(List));
        tempCell->val = i;
        tempCell->next = NULL;
        current->next = tempCell;
        current = current->next;
    }
    current->next = head;
    return head;
}

void Find(List * head, int numSize, int k) {
    int i;
    List * current, * tempCell, * del, * start;
    start = malloc(sizeof(List));
    start->next = head;
    current = start;
    while (current->next != current) {
        for (i = 0; i < k; i++) {
            tempCell = current;
            current = current->next;
        }
        printf("%d ", current->val);
        del = current;
        tempCell->next = current->next;
        current = tempCell;
        free(del);
    }
    printf("%d\n", current->val);
    free(current);
}

int main() {
    int numSize, k;
    List * head;
    scanf("%d%d", &numSize, &k);
    head = InitList(numSize);
    Find(head, numSize, k);

    return 0;
}