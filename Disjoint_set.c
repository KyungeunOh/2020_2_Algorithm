//
//  main.c
//  Ex6
//
//  Created by Kyungeun on 2020/10/13.
//

#include <stdio.h>
// a b c d e f g h i
// 0 1 2 3 4 5 6 7 8
#define size 9

int root[size];
int rank[size];

void make_set(void){ //노드 x를 유일한 원소로 하는 집합 만들기
    for(int i=0;i<size;i++){
        root[i]=i;
        rank[i]=0;
    }
}
int find(int x){ // 노드 x가 포함된 트리의 루트 리턴
    if(root[x]==x) return x;
    else return root[x]=find(root[x]); //재귀함수
}
void _union(int x,int y){ //x와 y 들어있는 집합 합치기
    x=find(x); //루트 찾기
    y=find(y);
    if(x==y) return;
    
    if(rank[x]<rank[y]) root[x]=y; // rank를 비교하여 효율적으로 합치기
    else{
        root[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
int main(){
    make_set();
    for(int i=0;i<size;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        _union(x,y);
    }
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d %d\n",i,root[i]);
    }
}
