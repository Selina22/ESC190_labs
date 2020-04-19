//
//  main.c
//  lab4
//
//  Created by Selina Wan on 2019-02-08.
//  Copyright © 2019 Selina Wan. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int key;
    unsigned int valid;
} keyType;

typedef struct {
    int *store;
    unsigned int size;
    unsigned int end;
} HeapType;





int initHeap (HeapType *pHeap,int size){
    if (pHeap==NULL){
        return -1; //failure
    }
    else{
        pHeap->size=size;
        pHeap->store=(int *)malloc(size*sizeof(int));
        pHeap->end=0;
        return 0;
    }
}

int inhelper(HeapType *pHeap, int **output, int position, int index){
    int end=pHeap->end;
    if((2*position+1)<end){
        index=inhelper(pHeap,output,2*position+1,index);
    }
    (*output)[index]=(pHeap->store)[position];
    index=index+1;
    if((2*position+2)<end){
        index=inhelper(pHeap,output,2*position+2,index);
    }
    return index;
}


int inorder(HeapType *pHeap, int **output, int *o_size){
    if(pHeap==NULL){
        return -1;
    }
    if(output==NULL){
        return -1;
    }
    *output=(int *)malloc((pHeap->size)*sizeof(int *));
    *o_size=pHeap->end+1;
    *o_size=inhelper(pHeap,output,0,0);
    return 0;
}

int prehelper(HeapType *pHeap, int **output, int position, int index){
    int end=pHeap->end;
    (*output)[index]=(pHeap->store)[position];
    index=index+1;
    if((2*position+1)<end){
        index=prehelper(pHeap,output,2*position+1,index);
    }
    if((2*position+2)<end){
        index=prehelper(pHeap,output,2*position+2,index);
    }
    return index;
}

int preorder(HeapType *pHeap, int **output, int *o_size){
    if(pHeap==NULL){
        return -1;
    }
    if(output==NULL){
        return -1;
    }
    *output=(int *)malloc((pHeap->size)*sizeof(int *));
    *o_size=pHeap->end+1;
    *o_size=prehelper(pHeap,output,0,0);
    return 0;
}



int main(void){
    int i;
    int *output=NULL;
    int o_size=0;
    HeapType *tree=malloc(sizeof(HeapType));
    initHeap(tree, 255);
    (tree->store)[0]=100;
    (tree->store)[1]=99;
    (tree->store)[2]=98;
    (tree->store)[3]=97;
    (tree->store)[4]=96;
    (tree->store)[5]=95;
    (tree->store)[6]=94;
    (tree->end)=6;
    preorder(tree,&output,&o_size);
    for(i=0;i<tree->end+1;i++){
        printf("%d\n",(tree->store)[i]);
    }
    printf("%d\n",tree->end);
    return 0;
}
