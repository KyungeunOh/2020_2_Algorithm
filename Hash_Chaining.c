//
//  main.c
//  Ex5
//
//  Created by Kyungeun.
//

#include <stdio.h>
#include <stdlib.h>
#define hashSize 13

typedef struct Node{ // 값을 담을 node 구조체 선언
    int value;
    struct Node* next; // 체이닝
}node;

typedef struct Hash{ // hashtable을 위한 구조체
    node *head;
}hash;

hash *hashtable;

int makekey(int value){
    return value % hashSize;
}

node *makenode(int value){ // 하나의 node 생성
    node *new = malloc(sizeof(node));
    new->value=value;
    new->next=NULL;
    return new;
}

void setHash(int value){
    int key = makekey(value);
    node *new = makenode(value); // node 제작
    if(hashtable[key].head==NULL){ // key에 해당하는 hashtable이 비어있을 때
        hashtable[key].head=new;
    } else{ // key에 해당하는 hashtable이 차있을 때
        new->next=hashtable[key].head; // 기존 node의 앞에 배치
        hashtable[key].head=new;
    }
}

void print(){
    for(int i=0;i<hashSize;i++){
        printf("<%d> ",i);
        if(hashtable[i].head!=NULL){
            node* temp=hashtable[i].head; // 노드에 연결된 node가 있을 경우 가리키기 위한 temp
            while(temp->next!=NULL){
                printf("%d ",temp->value);
                temp=temp->next;
            }
            printf("%d ",temp->value);
        }printf("\n");
    }
}

int main(){
    hashtable = (hash*)malloc(sizeof(hash)*13);
    for(int i=0;i<hashSize;i++){
        hashtable[i].head=NULL;
    }
    
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
