#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int w[6] = {2,10,13,17,22,42};
int tmp_w[6] = {2,10,13,17,22,42};
int W=52;
int x[6]={0,};
int tmp_x[6]={0,};

int promising(int i, int weight, int total){
    if(weight+total >= W && (weight==W || weight+w[i+1] <= W)) return 1;
    else return 0;
}

void print(){
    for(int i=0;i<6;i++){
        if(x[i]!=0){
            printf("%d ",x[i]);
        }
    } printf("\n");
}

void sum_of_subset(int i, int weight, int total){
    if(promising(i, weight, total)){ // i번째 원소의 조합 유망여부
        if(W==weight) {
            print(); // 정답
        } else{
            x[i+1]=w[i+1];
            sum_of_subset(i+1, weight+w[i+1], total-w[i+1]); // 가중치 포함했을 때
            x[i+1]=0;
            sum_of_subset(i+1, weight, total-w[i+1]); // 가중치 포함 안했을 때
        }
    }
}

int estimate(int n,int total){
    int i,j,k,m,mprod,weight=0;
    int numnodes; // 탐색에 소비한 노드 개수
    int prom_child[2]={0,}; // 현재 깊이에서 유망한 자식 노드값
    int f=0; // 유망 여부 판별
    
    i=0;
    numnodes=1;
    m=1;
    mprod=1;
    
    while(m!=0 && i!=2){ // n 안에 level이 있을 때 동작
        mprod *= m;
        numnodes += mprod*2;
        i++;
        m=0;
        for(k=0;k<2;k++){ // 0으로 초기화
            if(k==0){
                prom_child[k]=0;
            }
        }
        
        for(j=0;j<2;j++){
            if(tmp_w[j]!=0){
                tmp_x[i]=j;
                if(promising(i, weight, total)){ // promising 확인 후 포함
                    m++;
                    prom_child[j]=tmp_w[j];
                }
            }
        }
        
        if(m!=0){ // 난수를 지정하여 경로 설정
            while(f=0){
                j=rand()%2; // 랜덤으로 수 결정
                if(prom_child[j]!=0){ // promising 시 유망여부 변화
                    f=1;
                }
            }
            tmp_x[i]=j;
            tmp_w[j]=0;
            weight+=prom_child[j];
            total-=prom_child[j];
            f=0;
        }
    }
    return numnodes;
}

int main(){
    int total=0, numnode=0, total_numnode=0;
    srand((unsigned int)time(NULL));
    clock_t start, end;
    float run_time, run_sum=0;
    
    for(int i=0;i<6;i++){
        total+=w[i]; // 가지치기용 모든 원소 합 저장
    }
    printf("BackTracking\n");
    sum_of_subset(-1, 0, total);
    
    printf("\nMonte Carlo\n");
    for(int i=0;i<20;i++){
        start=clock();
        numnode = estimate(6,total);
        end=clock();
        run_time=(float)(end-start);
        run_sum += run_time;
        
        printf("%d run : %d개\n",i+1,numnode);
        
        for(int p=0;p<6;p++){ // 변환을 원본화
            tmp_w[p]=w[p];
            tmp_x[p]=x[p];
        }
        total_numnode+=numnode;
    }
    printf("평균 노드 개수 : %d개\n",total_numnode/20);
    printf("평균 수행시간 : %.3fms\n",run_sum/20);
}

