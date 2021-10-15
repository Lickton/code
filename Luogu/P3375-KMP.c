#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000005

void BuildNext(char * pattern, int lenP, int * next) {
    int i = 1, j = 0;
    while (i < lenP) {
        if (pattern[i] == pattern[j])
            next[i++] = next[i-1] + 1;
        else if (j != 0)
            j = next[j-1];
        else
            next[i++] = 0;
    }
}

int main() {
    char text[MAXSIZE], pattern[MAXSIZE];
    scanf("%s%s", text, pattern);
    int lenT = strlen(text), lenP = strlen(pattern);
    int next[lenP], i = 0, j = 0;
    if (lenP > lenT)
        return 0;
    BuildNext(pattern, lenP, next);
    while (i < lenT) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (text[i] != pattern[j] && j != 0)
            j = next[j-1];
        else
            i++;
        if (j == lenP) {
            printf("%d\n", i - j + 1);
            j = next[j-1];
        }
    }
    for (int i = 0; i < lenP; i++)
        printf("%d ", next[i]);
    return 0;
}