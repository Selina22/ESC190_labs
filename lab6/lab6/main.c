//
//  main.c
//  lab6
//
//  Created by Selina Wan on 2019-03-24.
//  Copyright © 2019 Selina Wan. All rights reserved.
//

#include <stdio.h>
unsigned char FSR(unsigned char x);
unsigned char prng(unsigned char x, unsigned char pattern);
int crypt(char *data, unsigned int size, unsigned char password);

unsigned char FSR(unsigned char x) {
    unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
    unsigned char r = x >> 1;        /* shift right   */
    unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
    r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
    return r;
}

unsigned char prng(unsigned char x, unsigned char pattern) {
    unsigned char newx=FSR(x);
    return newx^pattern;
}

int crypt(char *data, unsigned int size, unsigned char password) {
    unsigned int prngVal=password;
    int i;
    if(data==NULL){
        return -1;
    }
    if(size<1){
        return -1;
    }
    if(password==0){
        return -1;
    }
    for(i=0;i<size;i++){
        prngVal=prng(prngVal,0xb8);
        data[i]=data[i]^prngVal;
    }
    return 0;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
