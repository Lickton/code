/*
 * File name:   OlympicsGames
 * Author:      Lickton @github
 * Date:        2021.10.8
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30

typedef struct Rank {
    int ** rank;
    char ** country;
    int size;
    int length;
} list;

void Init(list * t);
void PrintMenu(void);
void PrintAll(list * t);
void Find(list * t);
void FindName(list * t);
void Delete(list * t);
void Insert(list * t);
void swap(int * m, int * n);

int main() {
    list * t = (list *)malloc(sizeof(list));
    Init(t);
    int choice;
    while (1) {
        PrintMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Find(t);
            break;
        case 2:
            FindName(t);
            break;
        case 3:
            Delete(t);
            break;
        case 4:
            Insert(t);
            break;
        case 5:
            PrintAll(t);
            break;
        default:
            return 0;
            break;
        }
    }
    return 0;
}

void Init(list * t) {
    int count;
    t->length = MAXSIZE - 5;
    t->size = MAXSIZE;
    t->rank = (int **)malloc(sizeof(int *)*MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->rank[i] = (int *)malloc(sizeof(int)*4);
    t->country = (char **)malloc(sizeof(char *)*MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->country[i] = (char *)malloc(sizeof(char)*MAXSIZE);
    count = t->length = MAXSIZE - 5;
    FILE * fp;
    fp = fopen("winners.txt", "r");
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%[^\n]", t->country[i]);
        fscanf(fp, "%d%d%d%d\n",(t->rank)[i], (t->rank)[i]+1, (t->rank)[i]+2, (t->rank)[i]+3);
    }
}

void PrintMenu(void) {
    printf("\n\n1. Enter the ranking to get the corresponding national medal list information\n");
    printf("2. Enter the name of the country and get its medal ranking\n");
    printf("3. According to the ranking, delete the medal list information of the corresponding country\n");        
    printf("4. Insert a record (on the medal list)\n");
    printf("5. Output medal table information\n");
    printf("Press 0 to quit.\n\n");
}

void Find(list * t) {
    int index;
    printf("\nPlease enter her rank:");
    scanf("%d", &index);
    if (index > t->length || index < 1) {
        printf("Out of bound!");
        return;
    }
    index--;
    printf("%dst %s\n", index, t->country[index]);
    printf("Gold: %d    Silver: %d  Bronze: %d  Total: %d\n", (t->rank)[index][0], (t->rank)[index][1], (t->rank)[index][2], (t->rank)[index][3]);
}

void PrintAll(list * t) {
    int count = t->length;
    for (int i = 0; i < count; i++) {
        printf("%dst %s\n", i+1, t->country[i]);
        printf("Gold: %d    Silver: %d  Bronze: %d  Total: %d\n", (t->rank)[i][0], (t->rank)[i][1], (t->rank)[i][2], (t->rank)[i][3]);
    }
}

void FindName(list * t) {
    char ch[MAXSIZE];
    int flag = 0;
    printf("Please enter the name of the country:");
    scanf("\n%[^\n]", ch);
    for (int i = 0; i < MAXSIZE; i++) {
        if (!strcmp(ch, t->country[i])) {
            printf("She is the %dst.", i+1);
            flag = 1;
            break;
        }
    }
    if (!flag)
        printf("She is not on the table!\n");
}

void Delete(list * t) {
    int toBedel;
    t->length--;
    if (t->length <= 0) {
        printf("All deleted!");
        return;
    }
    printf("Which country do you want to delete?");
    scanf("%d", &toBedel);
    for (int i = toBedel-1; i < t->length; i++) {
        for (int j = 0; j < 4; j++) {
            t->rank[i][j] = t->rank[i+1][j];
        }
        strcpy(t->country[i], t->country[i+1]);
    }    
}

void Insert(list * t) {
    int i;
    char ch[MAXSIZE], temp[MAXSIZE];
    t->length++;
    if (t->length > MAXSIZE) {
        printf("Out of size!");
        return;
    }
    printf("What the name of your country?");
    scanf("%s", ch);
    strcpy(t->country[t->length], ch);
    printf("How many medals does your country win?");
    t->rank[t->length][3] = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &(t->rank[t->length][i]));
        t->rank[t->length][3] += t->rank[t->length][i];
    }
    for (i = 0; t->rank[i][0] >= t->rank[t->length][0]; i++);
    for (; i < t->length; i++) {
        for (int j = 0; j < 4; j++) {
            swap(&(t->rank[i][j]), &(t->rank[t->length][j]));
        }
        strcpy(temp, t->country[i]);
        strcpy(t->country[i], t->country[t->length]);
        strcpy(t->country[t->length], temp);
    }
}

void swap(int * m, int * n) {
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}