/*
 * File name:   BedRoomInfro
 * Author:      Lickton @github
 * Date:        2021.10.10
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 20
#define min(m, n) m < n ? m : n

typedef struct Room {
    char ** name;
    char ** id;
    char ** birth;
    char ** favor;
    int * room;
    int size;
    int len;
} sqlist;

void Init(sqlist * t);
void PrintMenu(void);
void FindID(sqlist * t);
void FindRoom(sqlist * t);
void DeleteID(sqlist * t);
void Insert(sqlist * t);
void OutPutID(sqlist * t);
void OutPutRoom(sqlist * t);
int EasyAtoi(char * s);
int removeDuplicates(int* nums, int numsSize);

int main() {
    sqlist * t = (sqlist *)malloc(sizeof(sqlist));
    Init(t);
    while (1) {
        int choice;
        PrintMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            FindID(t);
            break;
        case 2:
            FindRoom(t);
            break;
        case 3:
            DeleteID(t);
            break;
        case 4:
            Insert(t);
            break;
        case 5:
            OutPutID(t);
            break;
        case 6:
            OutPutRoom(t);
            break;
        default:
            return 0;
            break;
        }
    }
}

void Init (sqlist * t) {
    t->len = 12;
    t->size = MAXSIZE;
    FILE * fp;
    fp = fopen("Roommate.txt", "r");
    t->name = (char **)malloc(sizeof(char*) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->name[i] = (char *)malloc(sizeof(char) * MAXSIZE);
    t->id= (char **)malloc(sizeof(char*) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->id[i] = (char *)malloc(sizeof(char) * MAXSIZE);
    t->birth= (char **)malloc(sizeof(char*) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->birth[i] = (char *)malloc(sizeof(char) * MAXSIZE);
    t->favor= (char **)malloc(sizeof(char*) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
        t->favor[i] = (char *)malloc(sizeof(char) * MAXSIZE);
    t->room= (int *)malloc(sizeof(int) * MAXSIZE);
    for (int i = 0; i < 12; i++) {
        fscanf(fp, "%s%s%s%s%d", t->name[i], t->id[i], t->birth[i], t->favor[i], t->room+i);
    }
}

void PrintMenu(void) {
    printf("\n1.输入学号，得到相应同学姓名、出生年月、爱好信息\n");
    printf("2.输入学生寝室号，得到相应寝室所有同学姓名\n");
    printf("3.根据学号，删除相应同学所有基础信息\n");
    printf("4.插入一条记录（新增一名同学信息）\n");
    printf("5.按学号升序输出信息表\n");
    printf("6.按寝室号升序输出信息表\n");
    printf("输入0退出\n\n");
}

void  FindID(sqlist * t) {
    char temp[MAXSIZE];
    printf("请输入学号:");
    scanf("%s", temp);
    for (int i = 0; i < t->len; i++) {
        if (!strcmp(temp, t->id[i])) {
            printf("%s %s %s\n", t->name[i], t->birth[i], t->favor[i]);
            return;
        }
    }
    printf("他不在这几个寝室里!");
}

void FindRoom(sqlist * t) {
    int temp, flag = 0;
    printf("请输入寝室号:");
    scanf("%d", &temp);
    for (int i = 0; i < t->len; i++) {
        if (temp == t->room[i]) {
            printf("%s\n", t->name[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("没这寝室...");
    }
}

void DeleteID(sqlist * t) {
    char temp[MAXSIZE];
    int place = -1;
    if (t->len <= 0) {
        printf("没人咋还能删啊，肯定不能啊!");
        return;
    }
    printf("想删除谁？报上他的学号:");
    scanf("%s", temp);
    for (int i = 0; i < t->len; i++)
        if (!strcmp(temp, t->id[i])) {
            place = i;
            break;
        }
    if (place == -1) {
        printf("没这号人");
        return;
    }
    for (int i = place; i < t->len; i++) {
        t->name[i] = t->name[i+1];
        t->id[i] = t->id[i+1];
        t->birth[i] = t->birth[i+1];
        t->favor[i] = t->favor[i+1];
        t->room[i] = t->room[i+1];
    }
    t->len--;
}

void Insert(sqlist * t) {
    if (t->len + 1 >= MAXSIZE) {
        printf("这里已经满员了！");
        return;
    }
    printf("输入他的姓名、学号、生日、兴趣爱好、房间号:");
    scanf("%s%s%s%s%d", t->name[t->len], t->id[t->len], t->birth[t->len], t->favor[t->len], t->room+(t->len));
    t->len++;
}


void OutPutID(sqlist * t) {
    int temp[t->len];
    for (int i = 0; i < t->len; i++)
        temp[i] = EasyAtoi(t->id[i]);
    for (int i = 0; i < t->len - 1; i++) {
        for (int j = 0; j < t->len - 1; j++) {
            if (temp[j] > temp[j+1]) {
                int tmp = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = tmp;
            }
        }
    }
    for (int i = 0; i < t->len; i++) {
        for (int j = 0; j < t->len; j++) {
            if (temp[i] == EasyAtoi(t->id[j])) {
                printf("%s %s %s %s %d\n", t->name[j], t->id[j], t->birth[j], t->favor[j], t->room[j]);
            }
        }
    }
}

void OutPutRoom(sqlist * t) {
    int temp[t->len], count = 0;
    for (int i = 0; i < t->len; i++) {
        temp[i] = t->room[i];
    }
    for (int i = 0; i < t->len - 1; i++) {
        for (int j = 0; j < t->len - 1; j++) {
            if (temp[j] > temp[j+1]) {
                int tmp = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = tmp;
            }
        }
    }
    count = removeDuplicates(temp, t->len);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < t->len; j++) {
            if (temp[i] == t->room[j]) {
                printf("%s %s %s %s %d\n", t->name[j], t->id[j], t->birth[j], t->favor[j], t->room[j]);
            }
        }
    }
}

int EasyAtoi(char * s) {
    int res = 0, i;
    int length = strlen(s);
    for (i = 0; !isdigit(s[i]); i++);
    for (; i < length; i++) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

int removeDuplicates(int* nums, int numsSize){
    int i, j, ans = 1;
    if (numsSize == 0) 
        return 0;
    for(i = 0, j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
            ans++;
        }
    }
    return ans;
}