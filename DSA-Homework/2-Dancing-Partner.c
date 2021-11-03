#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 30
#define max(m, n) m > n ? m : n
#define min(m, n) m < n ? m : n

typedef struct {
    char * base;
    int head;
    int end;
} Queue;

void InitQueue(Queue * Q) {
    Q->base = (char *)malloc(MAXSIZE * sizeof(char));
    if (!Q->base)
        exit(-1);
    Q->head = Q->end = 0;
}

void EnQueue(Queue * Q, char e) {
    if ((Q->end + 1) % MAXSIZE == Q->head)
        exit(-1);
    Q->base[Q->end] = e;
    Q->end = (Q->end + 1) % MAXSIZE;
}

void DeQueue(Queue * Q, char * e) {
    if (Q->head == Q->end)
        exit(-1);
    *e = Q->base[Q->head];
    Q->head = (Q->head + 1) % MAXSIZE;
}

int main() {
    Queue M, F;
    char e, sex, rep, t, eat;
    int Mlen, Flen, Max, Min;
    FILE *fp;
    InitQueue(&M);
    InitQueue(&F);
    fp = fopen("Dancing-Partner.txt", "r");
    while (fscanf(fp, "%c%*c%c%*c", &e, &sex) != EOF) {
        if (sex == 'M')
            EnQueue(&M, e);
        else
            EnQueue(&F, e);
    }
    Mlen = (M.end - M.head + MAXSIZE) % MAXSIZE;
    Flen = (F.end - F.head + MAXSIZE) % MAXSIZE;
    Max = max(Mlen, Flen);
    Min = min(Mlen, Flen);
    printf("Man\tFemale\n");
    for (int i = 0, j = 0; i < Max || j < 2 * Min;i++, j++) {
        DeQueue(&M, &t);
        printf("%c\t", t);
        EnQueue(&M, t);
        DeQueue(&F, &t);
        printf("%c\n", t);
        EnQueue(&F, t);
    }
    return 0;
}