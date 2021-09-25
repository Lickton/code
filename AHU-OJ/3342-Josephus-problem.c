#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    int val;
    Position Next;
};

int main() {
    int total, k;
    scranf("%d", &total);
    while (scanf("%d", &k) != EOF) {
        
    }
}