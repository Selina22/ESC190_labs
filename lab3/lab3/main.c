//
//  main.c
//  lab3
//
//  Created by Selina Wan on 2019-01-29.
//  Copyright © 2019 Selina Wan. All rights reserved.
//

#include <stdio.h>

struct bstNode {
    int val;
    struct bstNode *l;
    struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode {
    int balance; /* -1 Left, 0 balanced, +1 Right */
    int val;
    struct avlNode *l;
    struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode {
    avlNode *pval;
    struct qNode *nxt;
};
typedef struct qNode qNode;

int add_bst(bstNode **root,int val) {
    if (root == NULL) { return -1; }
    if (*root == NULL) {
        *root=(bstNode *)malloc(1*sizeof(bstNode));
        (*root)->val=val;
        (*root)->l=NULL;
        (*root)->r=NULL;
    } else {
        if (((*root)->val)<val){
            add_bst(&(*root)->r,val);
        }
        else{
            add_bst(&(*root)->l,val);
        }
    }
    return 0;
}

int printTreeInOrder(bstNode *root){
    int r=0;
    if (root==NULL){
        return -1;
    }
    if (root->l != NULL){
        r=printTreeInOrder(root->l);
    }
    printf("%d\n",root->val);
    if (root->r != NULL){
        r=printTreeInOrder(root->r);
    }
    return 0;
}

int max(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int height(avlNode *n){
    if (n==NULL){
        return -1;
    }
    else{
        return max(height(n->l),height(n->r))+1;
    }
}

int isAVL(avlNode **root) {
    int balance=0;
    int lbal=0;
    int rbal=0;
    if(root==NULL){
        return -1;
    }
    else{
        lbal=height((*root)->l);
        rbal=height((*root)->r);
        balance=lbal-rbal;
        if(balance>1 || balance<-1){
            return -1;
        }
        else{
            return 0;
        }
    }
}

int rotate(avlNode **root, unsigned int Left0_Right1){
    avlNode *temp=NULL;
    if(root==NULL){
        return -1;
    }
    if(Left0_Right1==0){
        temp=(*root)->r;
        (*root)->r=temp->l;
        temp->l=*root;
        *root=temp;
        return 0;
    }else{
        temp=(*root)->l;
        (*root)->l=temp->r;
        temp->l=*root;
        *root=temp;
        return 0;
    }
}

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1){
    if(root==NULL){
        return -1;
    }else{
        if(MajLMinR0_MajRMinL1==0){
            rotate((&(*root)->r),1);
            rotate(root,1);
        }
        return 0;
    }
}

int main(void) {
    bstNode *root=NULL;
    add_bst(&root,5);
    add_bst(&root,3);
    add_bst(&root,1);
    add_bst(&root,4);
    add_bst(&root,7);
    add_bst(&root,6);
    add_bst(&root,8);
    printf("%d\n",printTreeInOrder(root));
    return 0;
}
