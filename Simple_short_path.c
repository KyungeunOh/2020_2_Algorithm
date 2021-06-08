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

void simple_Shortest_Path(void){
    int i,j,k,m;
    for(i=1;i<=N;i++){ // init
        for(j=1;j<=N;j++){
            D[i][j]=W[i][j];
        }
    }
    for(m=2;m<=N;m++){ // 최대 M개의 간선을 사용하는 경우
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                for(k=1;k<=N;k++){
                    if(D[i][j]>D[i][k]+W[k][j])
                        D[i][j]=D[i][k]+W[k][j];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    simple_Shortest_Path();
    printf("\n   =====D출력=====\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%3d",D[i][j]);
        }printf("\n");
    }
}
