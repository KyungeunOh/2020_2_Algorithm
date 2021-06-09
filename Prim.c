#include <stdio.h>

#define MAX 8 // 노드 수
#define INF 10000 // 연결 X

int W[MAX][MAX]={ // 인접행렬
    { 0, 11, 9, 8, INF, INF, INF, INF },
    { 11, 0, 3, INF, 8, 8, INF, INF },
    { 9, 3, 0, 15, INF, 12, 1, INF },
    { 8, INF, 15, 0, INF, INF, 10, INF },
    { INF, 8, INF, INF, 0, 7, INF, 4 },
    { INF, 8, 12, INF, 7, 0, INF, 5 },
    { INF, INF, 1, 10, INF, INF, 0, 2 },
    { INF, INF, INF, INF, 4, 5, 2, 0 }
};

int nearest[MAX]; // 연결 여부 확인
int distance[MAX];

int min(){ // 최소 거리를 갖는 정점 찾는 함수
    int v=0,i;
    for(i=0;i<MAX;i++){
        if(!nearest[i]){
            v=i;
            break;
        }
    }
    for(i=0;i<MAX;i++){
        if(!nearest[i]&&(distance[i]<distance[v])){
            // 연결하지 않은 간선들 (!nearest[i]) 중 최소 가중치값을 갖는 정점을 찾음
            v=i;
        }
    }
    return v;
}

void prim(int start){
    int i, v, vmin, sum=0;
    
    for(i=0;i<MAX;i++){
        distance[i]=INF; // 초기화
    }
    distance[start]=0;
    for(i=0;i<MAX;i++){
        vmin=min();
        nearest[vmin]=1; // 연결 여부
        
        if(distance[vmin]==INF) return;
        printf("[V%d] 연결 가중치 : %d\n",vmin+1,distance[vmin]);
        sum+=distance[vmin]; // 최종 거리
        for(v=0;v<MAX;v++){
            if(W[vmin][v]!=INF){
                if(!nearest[v] && (W[vmin][v]<distance[v])){
                    distance[v]=W[vmin][v]; // 간선 거리 갱신
                }
            }
        }
    }
    printf("Prim's algorithm : %d\n",sum);
}

int main()
{
    prim(0); // v1 부터 연결 시작
}
