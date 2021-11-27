#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * BuildNext(char * pattern, int patternSize) {
	int i = 1, j = 0, *next = (int*)malloc(sizeof(int)*patternSize);
	next[0] = 0;
	while (i < patternSize) {
		if (pattern[i] == pattern[j])
			next[i++] = next[j++] + 1;
		else if (pattern[i] != pattern[j] && j > 0)
			j = next[j - 1];
		else
			next[i++] = 0;
	}
	return next;
}

int main() {
	char pattern[10] = "马林鱼", ch;
	int j = 0, len = strlen(pattern), *next, count = 0, temp;
	next = BuildNext(pattern, len);
	FILE *fp;
	fp = fopen("/home/lickton/桌面/老人与海.txt", "r");
	for (ch = fgetc(fp); ch != EOF;){
		if (ch == pattern[j]) {
			j++;
            ch = fgetc(fp);
        }
		else if (ch != pattern[j] && j != 0)
			j = next[j - 1];
        else {
            ch = fgetc(fp);
        }
		if (j == len - 1) {
			count++;
			j = 0;
            ch = fgetc(fp);
		}
	}
	printf("马林鱼一共出现了%d次\n", count);
	fclose(fp);
	return 0;
}