//
//  main.c
//  Ex5_2_이차원
//
//  Created by Kyungeun.
//

#include <stdio.h>
#define hashSize 13

int hashtable[hashSize]={};

int makekey(int value){
    return value % hashSize;
}

void setHash(int value){
    int key = makekey(value);
    int i=0;
    for(;hashtable[key+(i*i)]!=0;i++); // 이차원조사
    hashtable[key+(i*i)]=value;
}

void print(){
    for(int i=0;i<hashSize;i++){
        printf("<%d> %d\n",i,hashtable[i]);
    }
}

int main() {
    setHash(10);
    setHash(20);
    setHash(30);
    setHash(40);
    setHash(33);
    printf("----------33추가----------\n");
    print();
    setHash(46);
    printf("----------46추가----------\n");
    print();
    setHash(50);
    printf("----------50추가----------\n");
    print();
    setHash(60);
    printf("----------60추가----------\n");
    print();
}
