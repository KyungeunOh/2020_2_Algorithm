#include <stdio.h>
#define n 5
#define MAX 50

int tsp(int arr[][MAX],int traveling[],int start,int N){
    int i,j,k,tmp,min=1000;
    int temp[MAX], mintmp[MAX];
    
    if(start == n-2) // 재귀 종료 조건
        return arr[traveling[n-2]][traveling[n-1]] + arr[traveling[n-1]][0];

    for(i=start+1;i<n;i++){
        for(j=0;j<n;j++)
            temp[j] = traveling[j];

        temp[start+1] = traveling[i];
        temp[i] = traveling[start+1];
        
        if(arr[traveling[start]][traveling[i]]+(tmp = tsp(arr,temp,start+1,n)) < min){ // min값과 동적을 이용한 경로 cost 비교
            min = arr[traveling[start]][traveling[i]] + tmp;
            for(k=0;k<n;k++)
                mintmp[k] = temp[k];
        }
    }
    
    for(i=0;i<n;i++)
        traveling[i] = mintmp[i];
    return min; // minimum 값 반환
}


int main(){
    int arr[MAX][MAX]  = {{0,8,13,18,20},{3,0,7,8,10},{4,11,0,10,7},{6,6,7,0,11},{10,6,2,1,0}}; // W 행렬
    int i;
    int traveling[MAX];
    
    for(i=0;i<n;i++)
        traveling[i] = i;
    
    printf("Minimum = %d\nWay = ", tsp(arr,traveling,0,n));
    for(i=0;i<n;i++)
        printf("%d -> ", traveling[i] + 1); // 경로 출력
    printf("1\n");
    return 0;
}
