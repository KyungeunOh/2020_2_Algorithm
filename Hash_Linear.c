//
//  main.c
//  EX5_1_선형
//
//  Created by Kyungeun.
//

#include <stdio.h>
#define hashSize 13

int hashtable[hashSize]={}; //hashtable로 사용할 1차원 배열 선언

int makekey(int value){
    return value % hashSize; // mod 13값 반환
}

void setHash(int value){
    int key = makekey(value); // key값 결정
    while(hashtable[key]!=0){ // key에 해당하는 hashtable이 차있을 때
        key++; // 선형 조사
    }
    hashtable[key]=value;
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
