#include <stdio.h>
#include <stdlib.h>

struct intlist {
    int *x;
    int end;
    int len;
};
typedef struct intlist intlist;


int init(intlist *l,int len) {
    if (l==NULL) {
        return -1;
    }
    (l->x) = (int *)malloc(len * sizeof(int));
    if ((l->x) == NULL) {
        return -1;
    }
    l->end = -1;
    l->len=len;
    return 0;
}
