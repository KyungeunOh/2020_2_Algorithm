#include <stdio.h>
#include <stdlib.h>
#define N 7
#define MAX 2000

// 전체적으로 index와 v뒤의 숫자를 일치하기 위해서 index+1인 상태로 프로그래밍

int W[MAX][MAX]={
    {0},
    {0,0,4,MAX,MAX,MAX,10,MAX},
    {0,3,0,MAX,18,MAX,MAX,MAX},
    {0,MAX,6,0,MAX,MAX,MAX,MAX},
    {0,MAX,5,15,0,2,19,5},
    {0,MAX,MAX,12,1,0,MAX,MAX},
    {0,MAX,MAX,MAX,MAX,MAX,0,10},
    {0,MAX,MAX,MAX,8,MAX,MAX,0}
}; // 행과 열 모두 index 0인 부분은 0 처리.
int D[MAX][MAX];
int P[MAX][MAX];

void floyd(void){
    int i,j,k;
    for(i=1;i<=N;i++){ // init
        for(j=1;j<=N;j++){
            P[i][j]=0;
            D[i][j]=W[i][j];
        }
    }
    for(k=1;k<=N;k++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(D[i][j]>D[i][k]+D[k][j]){ // k 지나갈 시 D[i][j]가 더 짧아지는 경우
                    P[i][j]=k;
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
}

void print_path(int a, int b){
    if(P[a][b]!=0){
        print_path(a, P[a][b]);
        printf("a%d ",8-P[a][b]);
        print_path(P[a][b], b);
    }
}

int main(int argc, const char * argv[]) {
    floyd();
    printf("\n   =====D출력=====\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%3d",D[i][j]);
        }printf("\n");
    }
    printf("\n   =====P출력=====\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%3d",P[i][j]);
        }printf("\n");
    }
    //a7=v1 a6=v2 a5=v3 a4=v4 a5=v3 a6=v2 a7=v1
    //aX == v(8-X)
    int a=(8-5),b=(8-2); // v3 -> v6 최단 경로
    printf("\n최단 거리 : %d\n최단 경로 : ",D[a][b]);
    printf("a%d ",(8-a));
    print_path(a, b);
    if(D[a][b]!=0) printf("a%d",(8-b)); // a=b일때
    printf("\n");
}
