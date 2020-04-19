#include <stdio.h>
#include <stdlib.h>

int bs(int *x,int size,int (*compare)(int x,int y)) {
    if(x==NULL){
        return -1;//false
    }
    if(size<=0){
        return -1;
    }
    int sort=0;
    int i,temp,first,next;
    while (sort==0){
        sort=-1;
        for(i=0;i<size-1;i++){
            first=x[i];
            next=x[i+1];
            if((*compare)(first,next)==0){
                temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                sort=0;
            }
        }
        if(sort==-1){
            break;
        }
    }
    return 0;//success
}

int lt(int x,int y) {
    if(x<y){
        return 0;//true
    }
    else{
        return -1;//false
    }
}

int gt(int x,int y) {
    if(x>y){
        return 0;//true
    }
    else{
        return -1;//false
    }
}
/* test code for bs.c
int main(void) {
    int i=0;
    int vals[10];
    vals[0]=0;
    vals[1]=322;
    vals[2]=53;
    vals[3]=64;
    vals[4]=10;
    vals[5]=58;
    vals[6]=92;
    vals[7]=84;
    vals[8]=4;
    vals[9]=29;
    for (i=0;i<10;i++){
        printf("%d ",vals[i]);
    }
    printf("\n");
    //HERE: call bs() with the appropriate comparison function
    bs(vals,10,gt);
    //bubble(vals,10);
    for (i=0;i<10;i++){
        printf("%d ",vals[i]);
    }
    printf("\n");
    return 0;
} */

typedef struct {
    int *store;
    unsigned int size;
    unsigned int end;
    int (*compare)(int x,int y);
} intHeap_T;

int store(intHeap_T* heap,int value) { //add in an element and then heapify
    if(heap==NULL){
        return -1; //false
    }
    (heap->store)[heap->end]=value;
    heap->end=heap->end+1;
    int end=(heap->end)-1;
    int first,next,temp,pos=0;
    while(end!=0){
        if(end%2==1){
            pos=(end-1)/2;
        }
        else if(end%2==0){
            pos=(end-2)/2;
        }
        first=(heap->store)[end];
        next=(heap->store)[pos];
        if((heap->compare)(next,first)==0){
            temp=(heap->store)[end];
            (heap->store)[end]=(heap->store)[pos];
            (heap->store)[pos]=temp;
            end=pos;
        }
        else{
            break;
        }
    }
    return 0;
}

int reheapify(intHeap_T* heap,int end,int parent){
    int Lchild=-1;
    int Rchild=-1;
    int temp=0;
    int max=0;
    if(parent*2+1<end){
        Lchild=parent*2+1;
    }
    if(parent*2+2<end){
        Rchild=parent*2+2;
    }
    if(Rchild==-1 & Lchild==-1){
        return 0;
    }
    else{
        if(Rchild==-1){
            if((heap->compare)((heap->store)[parent],(heap->store)[Lchild])==0){
                temp=(heap->store)[Lchild];
                (heap->store)[Lchild]=(heap->store)[parent];
                (heap->store)[parent]=temp;
                reheapify(heap,end,Lchild);
            }
        }
        else{
            if((heap->compare)((heap->store)[parent],(heap->store)[Lchild])==0 | (heap->compare)((heap->store)[parent],(heap->store)[Rchild])==0){
                if((heap->compare)((heap->store)[Lchild],(heap->store)[Rchild])==0){
                    max=Rchild;
                }
                else{
                    max=Lchild;
                }
            }
            temp=(heap->store)[max];
            (heap->store)[max]=(heap->store)[parent];
            (heap->store)[parent]=temp;
            reheapify(heap,end,max);
        }
    }
    return 0;
}

int retrieve(intHeap_T* heap,int *rvalue){
    if(heap==NULL){
        return -1;
    }
    rvalue=(heap->store);
    *rvalue=(heap->store)[0];
    int temp=heap->store[0];
    (heap->store)[0]=(heap->store)[(heap->end)-1];
    (heap->store)[(heap->end)-1]=temp;
    (heap->end)=(heap->end)-1;
    reheapify(heap,heap->end,0);
    return 0;
}

int hs(int *x,int size,int (*compare)(int x,int y)) {
    if(x==NULL){
        return -1;
    }
    if(size<=0){
        return -1;
    }
    int i,j,k;
    intHeap_T heap;
    heap.store=(int *)malloc(size*sizeof(int));
    heap.size=size;
    heap.end=0;
    heap.compare=lt;
    for(i=0;i<size;i++){
        store(&heap,x[i]);
    }
    for (i = 0; i < size; i++){
        j = size -1 -i;
        retrieve(&heap, &k);
        heap.store[j] = k;
    }
    int m = size-1;
    for (k = 0; k < size; k++){
        x[m] = heap.store[k];
        m = m - 1;
    }

    return 0;
}



int main(void){
//    intHeap_T* heap;
//    int i;
//    heap->store=(int *)malloc(1000*sizeof(int));
//    heap->size=1000;
//    heap->end=0;
//    heap->compare = lt;
//    store(heap,4);
//    store(heap,6);
//    store(heap,41);
//    store(heap,85);
//    store(heap,69);
//    store(heap,482);
//    store(heap,10);
//    int a=0;
//    a=retrieve(heap,NULL);
    int i;
    int vals[10];
    vals[0]=0;
    vals[1]=322;
    vals[2]=53;
    vals[3]=64;
    vals[4]=10;
    vals[5]=58;
    vals[6]=92;
    vals[7]=84;
    vals[8]=4;
    vals[9]=29;
    hs(vals,10,lt);
    for(i=0;i<10;i++){
        printf("%d ",vals[i]);
    }
    printf("\n");
    return 0;
}

