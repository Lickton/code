#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000010
char text[MAXSIZE], pattern[MAXSIZE];
int next[MAXSIZE];

void BuildNext(int lenP) {
    int i = 1, j = 0;
    while (i < lenP) {
        if (pattern[i] == pattern[j])
            next[i++] = ++j;
        else if (j != 0)
            j = next[j-1];
        else
            next[i++] = 0;
    }
}

int main() { 
    scanf("%s%s", text, pattern);
    int lenT = (int)strlen(text), lenP = (int)strlen(pattern);
    int i = 0, j = 0;
    memset(next, 0, strlen(pattern));
    BuildNext(lenP);
    while (i < lenT) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (j != 0)
            j = next[j-1];
        else
            i++;
        if (j == lenP) {
            printf("%d\n", i - j + 1);
            j = next[j-1];
        }
    }
    for (i = 0; i < lenP; i++)
        printf("%d ", next[i]);
    return 0;
}